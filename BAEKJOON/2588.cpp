#include<cstdio>

int main(void)
{
	int a;
	char b[4];
	int res, sum = 0, t = 1;
	scanf("%d %s", &a, b);
	for (int i = 2; i >= 0; i--)
	{
		res = a * (b[i] - '0');
		printf("%d\n", res);
		res *= t;
		sum += res;
		t *= 10;
	}
	printf("%d\n", sum);
}
