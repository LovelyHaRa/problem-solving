#include<cstdio>

int MIN(int a, int b) { return a < b ? a : b; }
int main(void)
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d\n", MIN(MIN(MIN(x, y), (w - x)), (h - y)));
}
