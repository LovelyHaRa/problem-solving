#include<cstdio>

int main(void)
{
	char c;
	int a[26] = { 0, };
	while (scanf("%c", &c))
	{
		if (c == 10) break; // enter
		a[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) printf("%d ", a[i]);
}