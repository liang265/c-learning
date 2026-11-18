#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void secret(void)
{
    printf(">>> 你跳到了 secret！这句话本来永远不会执行 <<<\n");
    exit(0);
}

void vulnerable(void)
{
    char buf[16];
    char line[128];

    printf("vulnerable 的地址 = %p\n", (void *)vulnerable);
    printf("secret     的地址 = %p\n", (void *)secret);
    printf("请输入: ");
    fflush(stdout);

    if (fgets(line, sizeof(line), stdin) == NULL)
        return;
    line[strcspn(line, "\n")] = '\0';

    strcpy(buf, line);
    printf("buf = %s\n", buf);
}

int main(void)
{
    vulnerable();
    printf("正常返回，没有崩溃\n");
    return 0;
}
