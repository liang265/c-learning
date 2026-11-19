#include <stdio.h>
#include <string.h>
void swap(char *x,char *y)
{char t;
t=*x;*x=*y;*y=t;}

int main(void)
{char a[100];
char *p=a;
int len;
fgets(a,sizeof(a),stdin);
a[strcspn(a,"\n")]=0;
len=strlen(a);
char *q=a+len-1;
while(p<q){swap(p,q);p++;q--;}
for(int b=0;b<len;b++){printf("%c",a[b]);}
return 0;
}

