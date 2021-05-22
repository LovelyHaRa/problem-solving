#include<stdio.h>

int main(void)
{
	char input[31],stack[30],*s=stack, c;
	int sum = 0, k = 1, i = 0, x = 0, y = 0;
	scanf("%s", input);
	for (; input[i] != '\0'; i++)
	{
		switch (input[i])
		{
		case '(':
			*(s++) = input[i];
			x++;
			k *= 2;
			if (input[i + 1] != '\0' && input[i + 1] == ')')
				sum += k;
			break;
		case '[':
			*(s++) = input[i];
			y++;
			k *= 3;
			if (input[i + 1] != '\0' && input[i + 1] == ']')
				sum += k;
			break;
		case ')':
			--s;
			x--;
			k /= 2;
			break;
		case ']':
			--s;
			y--;
			k /= 3;
			break;
		default:
			break;
		}
		if (s - stack < 0 || x<0 || y<0)
			break;
	}
	if ((s - stack) != 0 || x != 0 || y != 0)
		printf("0\n");
	else
		printf("%d\n", sum);
}