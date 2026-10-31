#include "stdio.h"
int is_prime(int n)
{
	int m, flag = 1;
	for (m = 2;m*m <= n;m++)
	{
		if (n % m == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int main(void)
{
	int i;
	for (i = 2;i <= 100;i++) {
		if (is_prime(i) == 1)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
	

}