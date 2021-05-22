#include<stdio.h>

int main(void)
{
	int stack[100001], *s = stack, n, i, data[100000], index = 0, pindex = 0;
	char p[200000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);
	i = 1;
	while (i <= n + 1 && index < n)
	{
		if (*(s - 1) == data[index])
		{
			--s;
			p[pindex++] = '-';
			index++;
			continue;
		}
		if (i <= n)
		{
			*(s++) = i++;
			p[pindex++] = '+';
		}
		else
			break;
	}
	if (index == n)
	{
		for (i = 0; i < pindex; i++)
			printf("%c\n", p[i]);
	}
	else
		printf("NO\n");
}