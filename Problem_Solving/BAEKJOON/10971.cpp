#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> dist;

int min(int a, int b) { return a < b ? a : b; }

// 지금까지의 경로 path와 방문여부가 주어졌을 때, 최소비용을 반환한다
int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength)
{
	// 기저 사례: 모든 경로를 탐색 했을 때
	if (path.size() == n)
	{
		// 시작점과 연결되어있는지 확인
		if (dist[path.back()][path[0]] > 0)
			return currentLength + dist[path.back()][path[0]];
		return 1987654321; // 연결 안되있으면 순회 불가능이므로 큰 값 리턴
	}
	int ret = 1987654321;
	// 모든 지점 탐색
	for (int i = 0; i < n; i++)
	{
		int here = path.back();
		// 방문 했거나 연결되어있지 않은 경우 건너뛰기
		if (visited[i] || dist[here][i] == 0) continue;
		visited[i] = true; // 방문 체크
		path.push_back(i); // 경로 추가
		// 다음 경로 탐색
		int cand = shortestPath(path, visited, currentLength + dist[here][i]);
		// 최소 비용 갱신
		ret = min(cand, ret);
		// 원상 복구
		visited[i] = false;
		path.pop_back();
	}
	return ret;
}

int main(void)
{
	cin >> n;
	dist.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	int res = 1987654321;
	// 모든 위치에서 시작
	for (int i = 0; i < n; i++)
	{
		// 시작점 path 추가 및 방문 체크
		vector<int> path(1, i);
		vector<bool> visited(n);
		visited[i] = true;
		// 최소 비용 갱신
		res = min(shortestPath(path, visited, 0), res);
	}
	cout << res << '\n';
}