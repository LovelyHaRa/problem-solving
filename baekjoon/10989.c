/* 카운팅 정렬 */
#include <stdio.h>

int main(void)
{
	int N, data, i, j, count[10001] = {0}, max = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &data);
		count[data]++;
		max = max < data ? data : max;
	}

	for (i = 1; i <= max; i++)
	{
		for (j = 0; j < count[i]; j++)
			printf("%d\n", i);
	}
}