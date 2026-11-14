#include <stdio.h>
int main(void)
{int sum;
for(int i=1;i<10;i++)
{
for(int n=1;n<=i;n++){sum=n*i;printf("%d*%d=%d\t",n,i,sum);}
printf("\n");
}
return 0;
}
