#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
const int M = 1000 * 1000 + 1;
int main(void)
{
	int n;
	cin >> n;
	// rgb값, 캐시배열
	vector<vector<int>> rgb(n, vector<int>(3)), cache(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];
	int res = M; // 최솟값 구하는 변수
	// 시작집의 모든 경우를 탐색
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// 첫번째 집이 해당 차례의 집일 경우에만 캐시에 저장
			if (i == j)
				cache[0][j] = rgb[0][j];
			// 그렇지 않은 경우는 아주 큰 값 저장
			else
				cache[0][j] = M;
		}
		// DP 탐색
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < 3; k++)
				cache[j][k] = min(cache[j - 1][(k + 1) % 3], cache[j - 1][(k + 2) % 3]) + rgb[j][k];
		}
		// 첫번째 집과 똑같은 색깔의 집은 최솟값 갱신이 불가
		for (int j = 0; j < 3; j++)
		{
			// 최솟값 갱신이 불가능한 경우
			if (i == j) continue;
			// 그렇지 않은 경우
			res = min(res, cache[n - 1][j]);
		}
	}
	cout << res << '\n';
}
