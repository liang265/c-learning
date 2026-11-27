#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void win(void)
{system("id");
exit(0);}

void vuln(void)
{char buf[30];
char line[128];
read(0,line,128);
memcpy(buf,line,128);}

int main(void)
{
printf("main= %p\n",(void *)main);
fflush(stdout);
vuln();
return 0;
}
