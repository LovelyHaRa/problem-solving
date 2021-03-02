#include<cstdio>

int main(void)
{
	int a, b, c, x;
	scanf("%d %d %d", &a, &b, &c);
	x = c - b <= 0 ? -1 : a / (c - b) + 1;
	printf("%d\n", x);
}