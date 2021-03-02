#include<stdio.h>

int main(void)
{
	int T;
	int test_case;
	long long x, y, distance, i;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		i = 1;
		scanf("%lld %lld", &x, &y);
		distance = y - x;
		while (i*i < distance)
			i++;
		if ((i*i) - i >= distance)
			printf("%lld\n", (long long)((i * 2) - 2));
		else
			printf("%lld\n", (long long)((i * 2) - 1));
	}

	return 0;
}