#include<cstdio>

#define MAX 1000001
#define MIN -1000001

int main(void)
{
	int max = MIN, min = MAX;
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		max = max < t ? t : max;
		min = min > t ? t : min;
	}
	printf("%d %d", min, max);
}