#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void secret(void)
{
    printf(">>> 你跳到了 secret！这句话本来永远不会执行 <<<\n");
    exit(0);
}

void vulnerable(char *input)
{
    char buf[16];
    strcpy(buf, input);
    printf("buf = %s\n", buf);
}

int main(int argc, char *argv[])
{
    printf("vulnerable 的地址 = %p\n", (void *)vulnerable);
    printf("secret     的地址 = %p\n", (void *)secret);
    vulnerable(argv[1]);
    printf("正常返回，没有崩溃\n");
    return 0;
}
