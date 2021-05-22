#include<cstdio>

int main(void)
{
	int a, b, v, t;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d\n", (v - b - 1) / (a - b) + 1);
}
