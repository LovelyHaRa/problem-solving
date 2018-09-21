#include<stdio.h>

int main(void)
{
	int N,n;
	int i, k, count = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &n);
		k = 2;
		while (k*k <= n)
		{
			if (n%k == 0)
				break;
			k++;
		}
		if (k*k > n && n != 1)
			count++;
	}
	printf("%d\n", count);
}