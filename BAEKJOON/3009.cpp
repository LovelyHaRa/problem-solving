#include<cstdio>

int main(void)
{
	int num[3][2] = { 0 };
	int x, y;
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &num[i][0], &num[i][1]);
	x = num[0][0];
	y = num[0][1];
	x = (x == num[1][0]) ? num[2][0] : ((x == num[2][0]) ? num[1][0] : x);
	y = (y == num[1][1]) ? num[2][1] : ((y == num[2][1]) ? num[1][1] : y);
	printf("%d %d\n", x, y);
}
