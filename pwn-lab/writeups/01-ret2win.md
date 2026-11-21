一，漏洞在哪
 函数vuln()
为什么strcpy危险？ 因为他不看复制的东西有多大，会造成溢出
buf声明了18个字节，但编译器给这片区域留了 32 字节——多出来的 14 字节是对齐填充
二，为什么可以利用
vuln的栈帧如下：
      saved rip偏移40
      saved rbp //（8个字节）偏移32
      buf //(32个字节)偏移0
为什么覆盖saved rip可以让程序跳到别的函数
因为程序执行完当前函数后，是靠saved rip来指路的
ret干了什么：
把 saved rip的值弹出来，放进cpu的指令指针寄存器里（RIP），让cpu跳过去执行
三，payload怎么造
偏移 40 是怎么量的？
用gdb,b打断点，r运行，&buf,$rbp查看地址
为什么 buf 只有 18 字节，偏移却是 40？
上面已经说了，电脑会自己补
为什么地址只写 3 个字节？
读到00，就停了，所以取小端的三个字节就好。0x401196 的八字节是 96 11 40 00 00 00 00 00，高 5 个字节本来就是 00。 原来的返回地址也是 0x000000000040xxxx，那 5 个 00 已经在栈上了，不写也是对的。
四、防护为什么没起作用
-fno-stack-protector关闭看栈保护（金丝雀），如果不关，程序会检测到溢出，直接崩溃
-no-pie 关掉 PIE，程序每次加载到固定的地址，所以 get_flag 的地址可以写死在脚本里。如果开着 PIE，get_flag 每次运行地址都不同，写死的地址就失效了——那时候得先泄漏一个地址（Day 12 干的事）。
实测数据
gdb 里：
  break vuln
  run AAAA
  p &buf   → 0x7fffffffdc e0
  p $rbp   → 0x7fffffffdd00

0xdd00 - 0xdce0 = 0x20 = 32        ← buf 到 rbp
32 + 8 = 40                        ← 加上 saved rbp，就是到 saved rip

get_flag 的地址：
  nm chal | grep get_flag → 0000000000401196 T get_flag

payload：
  41 41 ... 41 (40 个) 96 11 40

输出：
  FLAG{198756}
  returncode = 0
踩过的坑
exit(0) 为什么必须加?
get_flag 里 printf 没有 \n，且输出被脚本用管道接走，所以进了缓冲区。get_flag 执行完 return，返回地址是垃圾，进程 SIGSEGV 崩溃——缓冲区里那 15 字节跟着进程一起没了。

表现出来就是：returncode = -11、stdout 一片空白，看起来像「没打进去」，其实可能早打进去了。

加 exit(0) 后，exit 会先把所有 stdio 缓冲区冲出去再退出，所以既能看见 FLAG，返回码也变成 0。
