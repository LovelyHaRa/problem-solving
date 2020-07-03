#include<iostream>
#include<vector>

using namespace std;

int V;
vector<vector<int>> adj; // 인접 리스트 표현
vector<bool> visited; // 방문 여부
const int UNWATCHED = 0; // 다른 노드에 지배되지 않음
const int WATCHED = 1; // 다른 노드에 지배됨
const int INSTALLED = 2; // 카메라 설치됨
int installed; // 카메라 설치 대수

// here로부터 깊이 우선 탐색을 하고, here의 정보를 반환한다
int dfs(int here)
{
	visited[here] = true; // 방문 체크
	int children[3] = { 0,0,0 }; // 지배 정보 초기화
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)]; // 지배 정보 갱신
	}
	// 자손 노드 중 감시되지 않는 노드가 있을 경우 카메라를 설치
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED; // 카메라 설치됐음을 반환
	}
	// 자손 노드 중 카메라가 설치된 노드가 있을 경우 설치할 필요가 없다
	if (children[INSTALLED]) {
		return WATCHED; // 지배됬음을 반환
	}
	// 그 이외의 경우 지배당하지 않음을 반환
	return UNWATCHED;
}

// 그래프를 감시하는 데 필요한 카메라의 최소 수를 반환한다
int installCamera()
{
	// 초기화
	installed = 0;
	visited = vector<bool>(V, false);
	// 모든 정점에 대해 dfs 탐색
	for (int u = 0; u < V; u++)
		if (!visited[u] && dfs(u) == UNWATCHED)
			installed++;
	return installed;
}

int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> V >> n;
		adj = vector<vector<int>>(V, vector<int>());
		// 연결 리스트 생성
		for (int i = 0; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << installCamera() << '\n';
	}
}