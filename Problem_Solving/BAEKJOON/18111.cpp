#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>> land(n, vector<int>(m));
	int maxHeight = 0, minHeight = 256; // 땅의 최대 높이 지점과 최소 높이 지점
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> land[i][j];
			// 땅의 최대 높이 지점과 최소 높이 지점을 구한다
			if (land[i][j] < minHeight) minHeight = land[i][j];
			if (land[i][j] > maxHeight) maxHeight = land[i][j];
		}
	}
	// 최소 시간, 최소 시간일 때의 높이
	int minTime = 1987654321, minTimeHeight = 64 * 10e6;
	// 최소 높이부터 최대 높이까지 탐색한다
	for (int h = minHeight; h <= maxHeight; h++)
	{
		int remove = 0, build = 0; // 제거한 블록 수, 설치한 블록 수
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int diff = land[i][j] - h; // 높이 차를 계산
				if (diff > 0) remove += diff; // 양수면 제거해야 한다
				else if (diff < 0) build += (-diff); // 음수면 설치해야 한다
			}
		}
		// 제거한 수(제거한 것을 블록으로 환산) + b 가 설치한 개수보다 많아야
		// 액션이 가능 하다
		if (remove + b >= build)
		{
			int time = remove * 2 + build; // 시간 계산
			// 최소 시간 갱신(같은 경우 높이를 갱신, 높이는 탐색할 수록 무조건 최대값)
			if (time <= minTime)
			{
				minTime = time;
				minTimeHeight = h;
			}
		}
	}
	cout << minTime << ' ' << minTimeHeight << '\n';
}