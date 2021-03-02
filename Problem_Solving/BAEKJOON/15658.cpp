#include<iostream>

using namespace std;

// 수열 크기, 수열, 연산자 개수(+, -, *, /), 최소/최대값
int n, a[11], oper[4], _min = 1987654321, _max = 0 - 1987654321;

// oper 인덱스에 따른 a,b의 연산 결과 반환
int calc(int a, int b, int op)
{
	switch (op)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
}

// 수열의 원소 위치에서 부분 합 sum을 현재 보유한 연산자로 가능한 모든 경우를 계산
void makeSum(int here, int sum)
{
	// 수열의 끝에 도달한 경우 최소/최대값 갱신
	if (here == n - 1)
	{
		_min = _min > sum ? sum : _min;
		_max = _max < sum ? sum : _max;
		return;
	}
	// 모든 연산자에 대해 계산
	for (int i = 0; i < 4; i++)
	{
		// 연산자가 있으면
		if (oper[i])
		{
			oper[i]--; // 연산자 개수 감소
			// 부분 합 갱신
			int t = !here ? calc(a[here], a[here + 1], i) : calc(sum, a[here + 1], i);
			makeSum(here + 1, t); // 다음 원소 탐색
			oper[i]++; // 원상 복구
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	makeSum(0, 0);
	cout << _max << '\n' << _min << '\n';
}