#include<stdio.h>

int main(void)
{
	int N;
	int d[1000];
	int i, j,t;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &d[i]);
	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (d[i] > d[j])
			{
				t = d[i];
				d[i] = d[j];
				d[j] = t;
			}
		}
	}
	for (i = 0; i < N; i++)
		printf("%d\n", d[i]);
}