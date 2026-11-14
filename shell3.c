#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void win(void)
{
printf(">>>拿到了shell<<<\n");
fflush(stdout);
system("/bin/sh");
}
void vulnerable(void)
{
char buf[16];
char line[64];
read(0,line,64);
memcpy(buf,line,64);
}
int main(void)
{
printf("win的地址=%p\n",(void*)win);
fflush(stdout);
vulnerable();
printf("正常返回，没有崩溃\n");
return 0;
}
