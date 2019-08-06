#include<cstdio>

int main(void)
{
	int a, b, c;
	int max, r;
	while(scanf("%d %d %d", &a, &b, &c),a&&b&&c)
	{
		max = (a > b) ? (a > c ? 1 : 3) : (b > c ? 2 : 3);
		switch (max)
		{
		case 1:
			r = b * b + c * c == a * a ? 1 : 0;
			break;
		case 2:
			r = a * a + c * c == b * b ? 1 : 0;
			break;
		case 3:
			r = a * a + b * b == c * c ? 1 : 0;
			break;
		}
		r ? printf("right\n") : printf("wrong\n");
	}
}