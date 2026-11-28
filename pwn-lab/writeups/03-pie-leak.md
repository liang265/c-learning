# 03-pie-leak
##漏洞在哪 
vuln 里 memcpy 固定拷 128 字节进 30 字节的 buf，没有长度检查。

##为什么能利用 
栈布局：buf → saved rbp → saved rip，偏移 40 字节可算。
##为什么这题明明有 PIE 却还能打
因为地址虽然是随机的，但是它只是每一次的基址随机，但是偏移永远不变
所以我们只要通过泄露的main算出固定的基址，再加上对应的偏移就好了

##payload 怎么构造
通过40个A占据偏移量，然后加ret使16字节对齐，最后加上我们想要程序去的地址

#偏移 40 是怎么量的
偏移是 gdb 量出来的
b vuln
r
p &buf
p $rbp
0xdd10 − 0xdcf0 = 0x20 = 32
32 + 8（saved rbp）= 40

#为什么必须先读才能拼 payload？如果顺序反过来会怎样？
先发 payload 再读，等于用不存在的地址拼了一堆字节。

#基址是怎么算出来的？公式写出来。
基址=main的泄露地址-main的偏移=win的地址-win的偏移

#p64(...) 和之前 struct.pack 是什么关系？
p64(x)  =  struct.pack('<Q', x)  =  x.to_bytes(8, 'little')


#为什么要垫一个 ret？如果去掉会怎样（你自己量到的 -11）？
call 压 8 字节返回地址，所以正常进函数时 rsp % 16 == 8；
我们用 ret 进去，只弹不压，进门时是 0。差这 8 字节，system() 里的 movaps 就崩。
##防护为什么没起作用
不是没起作用，而是我们把随机地址中不变的算出来了
#-fno-stack-protector 关了什么？
关了金丝雀

#真实场景里泄漏从哪来？
越界读（比如 printf("%s", buf) 而 buf 没有 \0）
未初始化内存（Day 6 那个 32767）
格式化字符串（printf(user_input) 里写了 %p）


##如果这题不给泄漏，还能打吗？
不知道，等 04-canary 和 05-ret2libc 讲。
