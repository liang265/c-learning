#include <stdio.h>
#include <string.h>
#include <stdlib.h>
__attribute__((force_align_arg_pointer))
void win(void)
{
printf(">>>拿到了shell<<<");
fflush(stdout);
system("/bin/sh");
}
void vulnerable(char *input)
{
char buf[16];
strcpy(buf,input);
}
int main(int argc,char*argv[])
{
printf("win的地址=%p\n",(void*)win);
vulnerable(argv[1]);
printf("正常返回，没有崩溃\n");
return 0;
}
