#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void win(void)
{
system("/bin/sh");
exit(0);
}
void vuln(void)
{
char buf[32];
read(0,buf,32);
write(1,buf,48);
read(0,buf,128);
}
int main()
{
vuln();
printf("正常输出");
return 0;
}
