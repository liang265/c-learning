#include <stdio.h>
#include <string.h>
int main(void)
{
char buf[100];
printf("请输入你要输入的东西:");
fgets(buf,sizeof(buf),stdin);
//buf[strcspn(buf,"\n")]='\0';
int lan;
lan=strlen(buf);
printf("%d",lan);
return 0;
}
