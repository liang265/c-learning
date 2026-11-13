今天学了什么
 第一次从空白文件独立写出程序（读一行打印长度）
 fgets 会把换行读进来，strlen 会算进去，所以要用 strcspn 截掉
 ret2win：24 字节覆盖到返回地址，跳到 win 函数拿到 shell

今天我踩的坑
 只有 stdio.h，用了 strlen/strcspn 触发隐式声明
 编译漏了 -fno-stack-protector -no-pie，地址变随机
 ./shell2 不带参数，argv[1] 是 NULL，段错误

卡在哪里
 栈对齐：直接 ret 进 win 会崩，加 force_align_arg_pointer 才行

明天干什么
 不用那个属性，用 ret gadget 对齐（真实世界的做法）
