#include<stdio.h>
int prime[20001];
int main(void)
{
	int n, k;
	int i, j;
	prime[1] = 1;
	for (i = 2; i*i <= 20000; i++)
	{
		if (prime[i]) continue;
		for (j = i + i; j <= 20000; j += i)
			prime[j] = 1;
	}
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (j = (k / 2); j >= 2; j--)
		{
			if (!prime[j] && !prime[k - j])
			{
				printf("%d %d\n", j, k - j);
				break;
			}
		}
	}
}