今天学了什么
权限位：-rw-r--r-- 拆成 rwx/r-x/r-x 三组
r=4 w=2 x=1，644 = rw-r--r--
chmod 000 之后 cat 自己都读不了 -> Permission denied
gdb：
next 跳过函数
step 钻进函数
continue 放行到下一个断点
bt 看调用栈，f 1 回到上层
kill 杀掉当前程序，delete 清断点
ASLR：
地址 = 页基址(随机) + 页内偏移(不变)
0x...41cd 尾数 1cd 永远不变，因为一页 4096 字节 = 0x1000
gdb 默认关掉 ASLR(set disable-randomization on)
卡在哪里
set disable_randomization 写成下划线，gdb 报 No symbol
run 之后答了 n，程序没重启
明天干什么
finish 命令
指针入门
