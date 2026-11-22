#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void win(void)
{
system("id");
exit(0);
}
void vuln(void)
{
char buf[18];
char line[64];
read(0,line,64);
memcpy(buf,line,64);
}
int main(void)
{
vuln();
printf("正常返回");
return 0;
}
