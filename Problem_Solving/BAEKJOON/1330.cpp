#include<cstdio>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	a >= b ? (a == b ? printf("==") : printf(">")) : printf("<");
}
