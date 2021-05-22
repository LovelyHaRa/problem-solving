#include<cstdio>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	while (!(a == b && !a))
	{
		printf("%d\n", a + b);
		scanf("%d %d", &a, &b);
	}
}
