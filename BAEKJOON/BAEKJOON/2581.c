#include<stdio.h>

int main(void)
{
	int M, N;
	int i, k, min, sum = 0;
	scanf("%d %d", &M,&N);
	for (i = M; i <= N; i++)
	{
		k = 2;
		while (k*k <= i)
		{
			if (i%k == 0)
				break;
			k++;
		}
		if (k*k > i && i != 1)
		{
			if (!sum)
				min = i;
			sum += i;
		}
	}
	if (sum)
		printf("%d\n%d\n", sum, min);
	else
		printf("-1");
}