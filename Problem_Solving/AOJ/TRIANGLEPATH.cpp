#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>cache; // 메모이제이션 캐시(y,x에서 맨 아래까지의 부분 경로의 합)
int n;

int max(int a, int b) { return a > b ? a : b; }

int path(const vector<vector<int>>& triangle, int y, int x)
{
	// 기저 조건: 삼각형 밑바닥에 도달했을 때
	if (y == n - 1) return triangle[y][x];
	// 메모이제이션
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	// 부분 경로의 최대값에 현재 좌표의 값을 더한다.
	return ret = max(path(triangle, y + 1, x), path(triangle, y + 1, x + 1)) + triangle[y][x];
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		vector<vector<int>> triangle(n, vector<int>(n));
		cache.resize(n, vector<int>(n, -1)); // 캐시 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];
		}
		cout << path(triangle, 0, 0) << '\n';
		cache.clear();
	}
}
