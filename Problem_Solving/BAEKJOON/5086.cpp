// 수학 문제
#include<cstdio>

using namespace std;

int main(void)
{
	int a, b;
	while (1)
	{
		scanf("%d %d", &a, &b);
		// 큰 수를 작은수로 나누어 떨어지면 약수거나 배수이다.
		// 약수 : a < b 인 경우
		// 배수 : a > b 인 경우
		if (!a && !b)
			break;
		if (a > b)
			a % b ? printf("neither\n") : printf("multiple\n");
		else
			b % a ? printf("neither\n") : printf("factor\n");
	}
}
