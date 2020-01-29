// 그리디 알고리즘
#include<iostream>

using namespace std;

int main(void)
{
	// 식
	char s[51];
	cin >> s;
	/*
		1. 숫자는 n에 저장
		2. 첫 - 이후의 값을 모두 더해 - 이전의 결과에서 빼주면 최솟값이다.
	*/
	// 숫자, 배열탐색, 결과값
	int n = 0, i = 0, res = 0;
	int flag = 0; // 첫 마이너스 발견시 1
	while (s[i] != '\0')
	{
		// 숫자 저장
		if (s[i] >= '0' && s[i] <= '9')
		{
			n *= 10;
			n += s[i] - '0';
		}
		// 기호 일 때.
		else
		{
			// -가 안나왔을 때,
			// 첫 -가 나왔을 때까지 결과를 저장하기 위해서 먼저 조건검사
			if (!flag)
				res += n;
			// - 이후는 계속 빼준다.
			else if (flag)
				res -= n;
			// 첫 - 일 때 플래그 변경
			if (s[i] == '-' && !flag)
				flag = 1;
			// 숫자 초기화
			n = 0;
		}
		i++;
	}
	// 마지막 수를 결과값에 더할지 뺄지 판단한다.
	res = flag ? res - n : res + n;
	cout << res << '\n';
}