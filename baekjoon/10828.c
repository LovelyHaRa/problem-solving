#include<stdio.h>

int main(void)
{
	int stack[10000], *s=stack, N, i;
	char c[6];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", c);
		if (c[0] == 'p' || c[0] == 't')
		{
			if (c[1] == 'u')
			{
				scanf("%d", s++);
				continue;
			}
			printf("%d\n", s == stack ? -1 : c[0]=='t' ? *(s-1) : *--s);
		}
		else if (c[0] == 's')
			printf("%d\n", s - stack);
		else
			printf("%d\n", s == stack);
	}
}