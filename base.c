#include <stdio.h>
int main(void)
{int n,base,change[8],a=0;
scanf("%d %d",&n,&base);
if(base==2)
{if(n==0){printf("0");return 0;}
while(n>0){change[a]=n%base;n=n/2;a++;}
for (int i=a-1;i>=0;i--)
{printf("%d",change[i]);}

}
return 0;
}
