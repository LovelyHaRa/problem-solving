#include<stdio.h>

int main(void)
{
	int queue[10000], N, front = 0, rear = 0;
	char c[6];
	scanf("%d", &N);
	while (N > 0)
	{
		scanf("%s", c);
		if (c[0] == 'p')
		{
			if (c[1] == 'u')
			{
				scanf("%d", &queue[rear++]);
				N--;
				continue;
			}
			printf("%d\n", front == rear ? -1 : queue[front++]);
		}
		else if (c[0] == 's')
			printf("%d\n", rear - front);
		else if (c[0] == 'e')
			printf("%d\n", front == rear);
		else if (c[0] == 'f')
			printf("%d\n", front != rear ? queue[front] : -1);
		else
			printf("%d\n", front != rear ? queue[rear - 1] : -1);
		N--;
	}
}