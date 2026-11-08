今天学了什么
- 字符串就是 char 数组加一个 \0，长度不存在，只能数到 \0 为止
- sizeof 数总字节数（含 \0），strlen 数字符数（不含）
- strcpy 不检查目标大小，只抄到 \0 为止，超出的部分写到隔壁
- 亲手溢出：char buf[8] 后面紧跟 int authorized，写 16 个 A 后 authorized 变成 0x41414141
- 常量长度溢出 gcc 会警告（-Wstringop-overflow），运行时长度一律不警告
- argv[1] 不给参数时是 NULL，strcpy 读地址 0 直接 segfault
- 全角逗号 ， 是 ef bc 8c，hexdump 一照就现形

卡在哪里
- 中文输入法打出全角逗号，gcc 报 expected ';' ',' or ')' before '*'
- main 参数之间漏逗号

明天干什么
- 栈上的溢出：看返回地址被覆盖后程序怎么跳
