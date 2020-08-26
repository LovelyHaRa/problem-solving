#include<cstdio>

void swap(long long &a, long long &b)
{
	long long t = a;
	a = b;
	b = t;
}

int main(void)
{
	long long t, x1, y1, x2, y2, r1, r2;
	long long dx, dy, add, sub, d;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		if (r1 > r2)
			swap(r1, r2);
		add = r1 + r2;
		add *= add;
		sub = r2 - r1;
		sub *= sub;
		dx = x1 - x2;
		dy = y1 - y2;
		d = dx * dx + dy * dy;
		
		if (add > d && sub < d)
			printf("2\n");
		else if (add == d || (d == sub && d != 0))
			printf("1\n");
		else if (add < d || sub > d)
			printf("0\n");
		else if (d == 0)
		{
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
	}
}