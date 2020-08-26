#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;
	while (n > 1) {
		// 1. 대소 판별
		int min = a < b ? a : b;
		int max = a > b ? a : b;
		// 2. 작은 값이 홀수 이고 두 수의 차가 1이면 대진 확정
		if (min % 2 && max - min == 1) break;
		// 3. 다음 라운드 번호 배정
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		// 4. 라운드 증가
		answer++;
		n /= 2;
	}

	return answer;
}