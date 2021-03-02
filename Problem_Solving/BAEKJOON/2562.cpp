#include<cstdio>

int main(void)
{
	int n, idx, max = 0;
	for (int i = 1; i < 10; i++)
	{
		scanf("%d", &n);
		if (max < n)
		{
			max = n;
			idx = i;
		}
	}
	printf("%d\n%d\n", max, idx);
}