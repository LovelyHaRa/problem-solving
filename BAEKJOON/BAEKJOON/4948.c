#include<stdio.h>
int prime[246913];
int main(void)
{
	int n;
	int i, j,count;
	prime[1] = 1;
	for (i = 2; i*i <= 246912; i++)
	{
		if (prime[i]) continue;
		for (j = i + i; j <= 246912; j += i)
			prime[j] = 1;
	}
	while (1)
	{
		scanf("%d", &n);
		if (!n)
			break;
		count = 0;
		for (i = n+1; i <= 2 * n; i++)
			if (!prime[i])
				count++;
		printf("%d\n", count);
	}
}