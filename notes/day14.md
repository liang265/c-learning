今天学了什么
 栈对齐：call 之前 rsp 必须是 16 的倍数，进函数时 rsp%16==8
 用 ret 不是 call 跳进去，少压 8 字节，对齐差一格，system 里的 movaps 会崩
 ret gadget：一条 c3，纯为了把 rsp 挪 8 字节
 嵌套循环：外层管行，内层管列

卡在哪里
 main 拼成 mian，链接器报 undefined reference to 'main'
 gcc 漏了 -o，ld 把 j99 当输入文件找不到
 内层 printf 加了 \n，打成了竖排

今天最大的收获
（自己写）
明天干什么
复习 5 条（栈对齐、ret gadget）
