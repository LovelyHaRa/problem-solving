#include <stdio.h>

int main(void)
{
	char num1[4], num2[4];
	int i;
	scanf("%s", num1);
	scanf("%s", num2);
	char temp;
	temp = num1[0];
	num1[0] = num1[2];
	num1[2] = temp;
	temp = num2[0];
	num2[0] = num2[2];
	num2[2] = temp;
	for (i = 0; i <3; i++)
	{
		if (num1[i] - '0' > num2[i] - '0')
		{
			printf("%s", num1);
			break;
		}
		else if (num1[i] - '0' < num2[i] - '0')
		{
			printf("%s", num2);
			break;
		}
	}
	if (i == 3)
		printf("%s", num1);

	return 0;
}