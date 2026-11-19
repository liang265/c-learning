#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{srand(time(NULL));
int a=rand()%100+1,guess;
for(int i=1;i<8;i++){
printf("请输入你猜的数字:\n");
scanf("%d",&guess);
if(guess==a){printf("对了，你猜了%d次\n",i);return 0;}
else if(guess<a){printf("小了\n");}
else{printf("大了\n");}
}
printf("次数用完了\n");
return 0;
}
