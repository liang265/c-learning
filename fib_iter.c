#include <stdio.h>
int main(void)
{
int f[999],n;
f[0]=0;
f[1]=1;
scanf("%d",&n);
for(int i=2;i<=999;i++){f[i]=f[i-2]+f[i-1];}
printf("%d",f[n]);
return 0;
}
