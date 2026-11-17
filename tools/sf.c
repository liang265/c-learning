#include <stdio.h>

void f(void)
{
    char buf[16] = "hello";
    printf("%s\n", buf);
}

int main(void)
{
    f();
    return 0;
}
