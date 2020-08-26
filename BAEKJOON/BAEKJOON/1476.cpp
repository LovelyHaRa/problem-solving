#include<iostream>

using namespace std;

int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;
	int year = 1;
	int ee=1, ss=1, mm=1;
	// 완전탐색
	while (ee != 15 || ss != 28 || mm != 19)
	{
		// 조건에 맞는 숫자이면 연도 출력
		if (e == ee && s == ss && m == mm )
		{
			cout << year << '\n';
			break;
		}
		// 나머지가 0이되면 1로 초기화
		ee = !((ee + 1) % 16) ? 1 : (ee + 1) % 16;
		ss = !((ss + 1) % 29) ? 1 : (ss + 1) % 29;
		mm = !((mm + 1) % 20) ? 1 : (mm + 1) % 20;
		year++;
	}
	// 끝까지 탐색했을 경우
	if (ee == 15 && ss == 28 && mm == 19)
		cout << year << '\n';
}