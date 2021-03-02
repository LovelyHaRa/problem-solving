#include<stdio.h>
int prime[1000001];
int main(void)
{
	int M, N;
	int i, j;
	prime[1] = 1;
	for (i = 2; i*i <= 1000000; i++)
	{
		if (prime[i]) continue;
		for (j = i + i; j <= 1000000; j += i)
			prime[j] = 1;
	}
	scanf("%d %d", &M, &N);
	for (i = M; i <= N; i++)
		if (!prime[i])
			printf("%d\n", i);
}