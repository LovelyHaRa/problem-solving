#include <stdio.h>

int main(void)
{
	char s[16];
	int i = 0, count = 0;
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++)
	{
		count += (s[i] - 'A') / 3 + 3;
		if (s[i] - 'A' == 18 || s[i] - 'A' == 21 || s[i]-'A'>=24)
			count--;
	}
	printf("%d", count);
	return 0;
}