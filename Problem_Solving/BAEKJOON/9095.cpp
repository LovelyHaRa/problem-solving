#include<iostream>

using namespace std;

int cnt;

// 재귀 완전탐색
void func(int x, int n)
{
	// n과 같으면 카운트 증가 후 리턴
	if (x == n)
	{
		cnt++;
		return;
	}
	// n을 초과하면 더이상 의미 없으므로 리턴
	else if (x > n)
		return;
	func(x + 1, n); // 1을 더해본다
	func(x + 2, n); // 2를 더해본다
	func(x + 3, n); // 3을 더해본다
	return;
}

int main(void)
{
	int t;
	cin >> t; // 테스트 케이스
	while (t--)
	{
		int n;
		cin >> n; // 입력
		cnt = 0; // 카운트 초기화
		func(0, n); // 완전 탐색
		cout << cnt << '\n';
	}
}