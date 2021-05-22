#include<stdio.h>

int main(void)
{
	int n, count = 0;
	int i = 1;

	scanf("%d", &n);
	while (1)
	{
		if (i>=n)
			break;
		count++;
		i += count * 6;
	}
	printf("%d", count+1);
}