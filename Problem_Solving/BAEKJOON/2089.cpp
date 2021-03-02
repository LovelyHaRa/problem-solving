#include<iostream>

using namespace std;

void f(int n)
{
	// 1. 0이면 리턴
	if (!n) return;
	// 2. n이 짝수이면
	if (-(n % 2) == 0)
	{
		// -(n/2) 값을 재귀 호출
		f(-(n / 2));
		cout << '0'; // 역순으로 출력하기 위해
	}
	// 3. n이 홀수이면
	else
	{
		// 양수이면 -(n/2) 값을 재귀 호출
		if (n > 0)
			f(-(n / 2));
		// 음수이면 (-n+1) /2 값을 재귀 호출
		else
			f((-n + 1) / 2);
		cout << '1'; // 역순으로 출력하기 위해
	}
}

int main(void)
{
	int n;
	cin >> n;
	if (!n) cout << 0;
	else f(n);
}