#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		n += 2; // 편의점 + 집 + 펜타포트
		// 집, 편의점, 펜타포트 좌표 페어 배열
		vector<pair<int, int>> pos(n);
		// 좌표 페어 배열 인덱스를 기반으로 한 인접 행렬
		vector<vector<bool>> adj(n, vector<bool>(n));
		// 위치 입력 받기
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			pos[i] = { x,y };
			adj[i][i] = 1; // 자기 자신은 무조건 연결
		}
		// 좌표를 기반으로 인접 행렬에 연결하기
		for (int i = 0; i < n - 1; i++)
			for (int j = 1; j < n; j++)
			{
				// 맨허튼 거리 구하기
				int dx = abs(pos[i].first - pos[j].first);
				int dy = abs(pos[i].second - pos[j].second);
				// 50*20 보다 작으면 연결 가능하다
				if (dx + dy <= 1000)
					adj[i][j] = adj[j][i] = 1;
			}
		// 플로이드 와샬 알고리즘
		// 중간지점
		for (int k = 0; k < n; k++)
			// 시작지점
			for (int i = 0; i < n; i++)
				// 도착지점
				for (int j = 0; j < n; j++)
					// 시작-중간 지점과 중간-도착 지점이 연결되어 있다면 시작-종료지점도 연결
					if (adj[i][k] && adj[k][j])
						adj[i][j] = 1;

		// 집과 펜타포트 락 페스티벌 장소가 연결되어 있다면 happy, 그렇지 않다면 sad 출력
		cout << (adj[0][n - 1] ? "happy\n" : "sad\n");
	}
}