#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	int cnt = 1; // 결과값 + 1
	// 탐욕스럽게 계산
	// b에서 a를 만들면 된다
	while (a < b && b)
	{
		// 1순위: 10으로 나눌 수 있는 경우
		if (b % 10 == 1)
			b /= 10;
		// 2순위: 2로 나눌 수 있는 경우
		else if (!(b % 2))
			b /= 2;
		// 이 외의 경우는 a로 만들 수 없는 경우다
		else
			break;
		cnt++;
	}
	// a와 b가 같으면 카운팅 출력, 그렇지 않으면 -1 출력
	cout << (a == b ? cnt : -1) << '\n';
}