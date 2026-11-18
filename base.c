#include <stdio.h>
int main(void)
{char table[]="0123456789abcdef";
int n,base,change[8],a=0;
scanf("%d %d",&n,&base);
if(n==0){printf("0");return 0;}
while(n>0){change[a]=n%base;n=n/base;a++;}
for (int i=a-1;i>=0;i--)
{printf("%c",table[change[i]]);}
return 0;
}
