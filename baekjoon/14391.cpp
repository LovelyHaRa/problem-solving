#include<iostream>
#include<vector>
#include<string>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> paper(n);
	for (int i = 0; i < n; i++)
		cin >> paper[i];
	int res = 0; // 최대값
	// 가로 조각은 0, 세로 조각은 1로 하는 비트마스크로 해결
	// 전체 경우의 수는 2^(m*n)개
	// 모든 경우의 수 탐색
	for (int i = 0; i < (1 << (n*m)); i++)
	{
		// 합, 현재 비트셋, 최상위 비트 위치
		int sum = 0, cur = i, msb = (1 << (n*m - 1));
		// 가로 조각 계산
		for (int j = 0; j < n; j++)
		{
			int num = 0;
			for (int k = 0; k < m; k++)
			{
				// 가로 조각은 0으로 표현함
				if ((cur&msb) == 0)
				{
					num *= 10;
					num += paper[j][k] - '0';
				} 
				// 조각이 끊기면 sum 갱신 후 숫자 리셋
				else
				{
					sum += num;
					num = 0;
				}
				// msb 한칸 씩 감소
				msb /= 2;
			}
			// 마지막 조각 sum 갱신
			sum += num;
		}
		// 세로 조각 계산
		for (int j = 0; j < m; j++)
		{
			// 첫 행의 j번째 위치부터 시작
			msb = (1 << ((m*n) - 1 - j));
			int num = 0;
			for (int k = 0; k < n; k++)
			{
				// 세로 조각은 1로 표현함
				if (cur&msb)
				{
					num *= 10;
					num += paper[k][j] - '0'; // 세로 탐색
				}
				// 조각이 끊기면 sum 갱신 후 숫자 리셋
				else
				{
					sum += num;
					num = 0;
				}
				// m개만큼 건너뛰기(세로로 탐색)
				msb /= (1 << m);
			}
			// 마지막 조각 sum 갱신
			sum += num;
		}
		// 최댓값 갱신
		res = max(res, sum);
	}
	cout << res << '\n';
}
