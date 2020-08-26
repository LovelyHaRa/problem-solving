// 수학 문제
#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int i = 2;
	// 소인수분해
	// i=2부터 시작, n과 나누어 떨어지면 i 출력 후 i로 나눔
	// 그렇지 않으면 i 1씩 증가
	// n을 더이상 나눌 수 없으면(1이되면) 종료
	while(n>1)
	{
		if (n%i == 0)
		{
			cout << i << '\n';
			n /= i;
			continue;
		}
		i++;
	}
}