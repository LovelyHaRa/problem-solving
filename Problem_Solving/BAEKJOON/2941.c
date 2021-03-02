#include <stdio.h>

int main(void)
{
	char s[101];
	int i = 0, count = 0;
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '=')
		{
			if (s[i - 1] == 'z' || s[i - 1] == 'c' || s[i - 1] == 's')
			{
				count++;
				if (s[i - 1] == 'z' && s[i - 2] == 'd')
					count++;
			}
		}
		else if (s[i] == '-')
		{
			if (s[i - 1] == 'c' || s[i - 1] == 'd')
				count++;
		}
		else if (s[i] == 'j')
		{
			if (s[i - 1] == 'l' || s[i - 1] == 'n')
				count++;
		}
	}
	printf("%d", i-count);
	return 0;
}