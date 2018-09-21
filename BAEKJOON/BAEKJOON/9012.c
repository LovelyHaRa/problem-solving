#include<stdio.h>

int main(void)
{
	int T, count, index;
	char c[51];
	scanf("%d", &T);
	while (T > 0)
	{
		scanf("%s", c);
		count = index = 0;
		while (c[index] != '\0' && count >= 0)
			c[index++] == '(' ? count++ : count--;
		printf("%s\n", !count ? "YES" : "NO");
		T--;
	}	
}