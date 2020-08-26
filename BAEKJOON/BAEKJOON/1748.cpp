#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int res = 0; // 결과
	int cnt = 1, div = 10; // 자리 개수, 나눌 수
	// 1. 1부터 n까지 탐색
	for (int i=1;i<=n;i++)
	{
		// 2. 현재 수가 0으로 나누어지면 자리수가 증가함을 의미
		if (i%div == 0)
		{
			div *= 10; // 자리수 기준 증가
			cnt++; // 자리수 증가
		}
		// 3. 자리수 누적
		res += cnt;
	}
	cout << res; // 결과 출력
}