#include <stdio.h>
int main()
{
int a,b;
char op;
scanf("%d %c %d",&a,&op,&b);
switch(op)
{case '+':
	printf("%d\n",a+b);
	break;
case '-':
	printf("%d\n",a-b);
	break;
case '*':
	printf("%d\n",a*b);
	break;
case '/':
	if(b==0)
	printf("不能除以0\n");
	else
	printf("%d\n",a/b);
	break;
default:
	printf("不支持的运算符\n");
	break;
}
return 0;
}
