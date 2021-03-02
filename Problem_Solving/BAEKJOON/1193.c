#include<stdio.h>

int main(void)
{
	int n;
	int i=0,count=1;
	scanf("%d",&n);
	while (i + count < n)
	{
		i += count;
		count++;
	}
	n -= i;
	if (count % 2 == 1)
		printf("%d/%d", ((count+1) - n), n);
	else
		printf("%d/%d", n, ((count+1) - n));
}