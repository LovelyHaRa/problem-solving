#include <stdio.h>

int main(void)
{
	int T, test_case;
	int H, W, N;
	int h, w;
	char num[5] = { 0 };
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d", &H, &W, &N);
		h = N%H;
		w = (N / H) + 1;
		if (h == 0)
		{
			h = H;
			w--;
		}
		printf("%d", h);
		if (w / 10 == 0)
			printf("%d%d\n", 0, w);
		else
			printf("%d\n", w);
	}
}