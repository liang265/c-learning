#include <stdio.h>
int main(void)
{int n,a[100],sum=0;
scanf("%d",&n);
for(int i=0;i<n;i++)
{scanf("%d",&a[i]);sum+=a[i];}
int max=a[0],min=a[0];
for(int e=0;e<n;e++)
{if(max<a[e]){max=a[e];}
if(min>a[e]){min=a[e];}
}
double adv;
adv=(double)sum/n;
printf("平均分:%.2lf\n",adv);
printf("最高分:%d\n",max);
printf("最低分:%d\n",min);
return 0;
}
