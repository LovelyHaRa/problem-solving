#include<cstdio>

int main(void)
{
	int w[50][2], r[50];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &w[i][0], &w[i][1]);
	for (int i = 0; i < n; i++)
	{
		r[i] = 1;
		for (int j = 0; j < n; j++)
		{
			if (w[i][0] < w[j][0] && w[i][1] < w[j][1])
				r[i]++;
		}
		printf("%d ", r[i]);
	}
	printf("\n");	
}