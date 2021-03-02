#include<cstdio>

int main(void)
{
	int div[42] = { 0, }, sum = 0;
	for (int i = 0; i < 10; i++)
	{
		int n;
		scanf("%d", &n);
		div[n % 42] = 1;
	}
	for (int i = 0; i < 42; i++)
		sum += div[i];
	printf("%d\n", sum);
}
