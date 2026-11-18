#include <stdio.h>
#include <string.h>
void swap(char *x,char *y)
{char t;
t=*x;*x=*y;*y=t;}

int main(void)
{char a[100];
int len,i=0,j;
fgets(a,sizeof(a),stdin);
a[strcspn(a,"\n")]=0;
len=strlen(a);
j=len-1;
while(i<j){swap(&a[i],&a[j]);i++;j--;}
for(int b=0;b<len;b++){printf("%c",a[b]);}
return 0;
}
