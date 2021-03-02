#include<cstdio>

void hanoi(int n, int from, int to)
{
	if (n == 0)
		return;
	else
	{
		hanoi(n - 1, from, 6 - from - to);
		printf("%d %d\n", from, to);
		hanoi(n - 1, 6 - from - to, to);
	}
}

int main(void)
{
	int N;
	scanf("%d",&N);
	printf("%d\n", (1 << N) - 1);
	hanoi(N, 1, 3);
}