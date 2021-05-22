#include<cstdio>

int main(void)
{
	int h, m;
	scanf("%d %d", &h, &m);
	if (m < 45)
	{
		h--;
		h = h < 0 ? 23 : h;
		m = 60 - (45 - m);
	}
	else
		m -= 45;
	printf("%d %d\n", h, m);
}
