#include <stdio.h>
long long memo[100];
long long fib(int n)
{if (n<=1)
return n;
else if (memo[n]!=-1)
return memo[n];
else
{memo[n]=fib(n-1)+fib(n-2);
return memo[n];}
}
int main(void)
{
for (int i =0;i<100;i++)
memo[i]= -1;
int n;
scanf("%d",&n);
printf("%lld\n",fib(n));
return 0;
}
