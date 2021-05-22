#include<cstdio>

int main(void)
{
	int y;
	scanf("%d", &y);
	printf("%d\n", (!(y % 4) && (y % 100)) || !(y % 400));
}
