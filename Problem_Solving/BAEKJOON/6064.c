#include<stdio.h>

int GCD(int a, int b) // 유클리드 호제법(재귀)를 이용한 최대 공약수 함수
{
	if (a%b == 0)
		return b;
	else
		GCD(b, a%b);
}

int main(void)
{
	int T; // TestCase
	int M, N, x, y; // input data
	int i; // 반복문 변수
	int answer,gcd; // 결과
	scanf("%d", &T);
	for (i = 0; i < T; i++) // 테스트 케이스만큼 반복
	{
		scanf("%d %d %d %d", &M, &N, &x, &y); // input
		answer = -1; // 해가 없을 경우 -1 출력
		gcd = M > N ? GCD(M, N) : GCD(N, M); // 최대공약수 구하기
		while (x <= (M*N) / gcd || y <= (M*N) / gcd)  // M, N의 최소 공배수가 카일 달력 해의 개수
		{
			if (x == y)
			{
				answer = x; // x=y일 때, x값이 해
				break;
			}
			// x, y 중 작은 값에 M, N을 더함
			if (x < y) x += M;
			else y += N;
		}
		printf("%d\n", answer); // 결과 출력
	}
}