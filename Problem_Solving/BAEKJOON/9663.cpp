// 백트래킹 dfs 문제
#include<iostream>
#include<cmath>

using namespace std;

int cnt = 0;
// 한행에는 퀸 하나만 존재할 수 있음을 이용한다
int col[15]= { 0, };
int N;

// 이전 행들을 체크 하면서 같은 행에 위치하거나 대각선에 위치하면 배치할 수 없다
bool isPossible(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (col[i] == col[row] || abs(col[i] - col[row]) == abs(i - row))
			return false;
	}
	return true;
}

void queen(int row)
{
	// 행을 모두 채우면 조건 만족
	if (row == N)
		cnt++;
	else
	{
		for (int i = 0; i < N; i++)
		{
			// 체크
			col[row] = i;
			if (isPossible(row))
				queen(row + 1); // 다음행으로 넘어간다
			else
				// 백트래킹
				col[row] = 0;
		}
	}
	// 백트래킹
	col[row] = 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	queen(0);
	cout << cnt << '\n';
}
