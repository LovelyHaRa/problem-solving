// 백트래킹 문제

#include<iostream>
#include<vector>

using namespace std;

vector<int> a; // 수열 저장
int oper[4]; // + - * /
int n;
int _max = -1987654321, _min = 1987654321;

// 연산 함수
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
	default:
		return 0;
	}
}

void back(int idx, int mid)
{
	// 식이 완성되었을 경우
	if (idx == n - 1)
	{
		// 최대값과 최솟값 여부를 확인한다
		_max = mid > _max ? mid : _max;
		_min = mid < _min ? mid : _min;
		return;
	}
	// 연산자 종류는 4개이다
	for (int i = 0; i < 4; i++)
	{
		// 연산자가 존재하면
		if (oper[i])
		{
			int tmp = mid; // 백트래킹을 위해 중간 계산값 저장
			oper[i]--; // 연산자 개수 감소
			// 중간값 계산
			mid = !idx ? calc(a[idx], a[idx + 1], i) : calc(mid, a[idx + 1], i);
			back(idx + 1, mid); // 다음 인덱스로 이동
			// 백트래킹 처리
			oper[i]++;
			mid = tmp; 
		}
	}
}

int main(void)
{	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	back(0, 0);
	cout << _max << '\n' << _min << '\n';
}