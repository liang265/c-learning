#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void get_flag()
{
printf("FLAG{198756}\n");
exit(0);
}
void vuln(char *s)
{
char buf[18];
strcpy(buf,s);
}
int main(int argc,char *argv[])
{
vuln(argv[1]);
printf("正常返回，没有覆盖");
return 0;
}
