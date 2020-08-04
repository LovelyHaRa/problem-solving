#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> adj; // 인접 리스트 구현
vector<int> check; // 방문 여부
vector<int> ans; // 정답 인풋
int idx = 1; // 정답 배열 현재 참조 위치 (1부터 시작)

// dfs 탐색
void dfs(int x)
{
	// 이미 탐색되었거나 정답 배열이 모두 참조 되었을 경우
	if (check[x] || idx==n)
		return;
	// 탐색 체크
	check[x] = 1;
	// 현재 정점으로부터 연결된 정점들을 모두 방문
	while (idx < n)
	{
		int y;
		// 연결된 정점 모두 탐색
		for (y = 0; y < adj[x].size(); y++)
		{
			// 정답 배열의 현재 위치의 값과 정점이 같으면
			if (ans[idx] == adj[x][y])
			{
				idx++; // 정답 배열 참조위치 증가
				dfs(adj[x][y]);  // dfs 재귀 탐색
				break; // 정점을 찾았으므로 멈춤
			}
		}
		// 정점을 못찾은 경우 멈춤
		if (y == adj[x].size()) break;
	}
}

int main(void)
{
	// 입력
	cin >> n;
	adj.resize(n + 1);
	check.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans.resize(n);
	for (int i = 0; i < n; i++)
		cin >> ans[i];
	// 1부터 dfs 탐색
	dfs(1);
	// 정답배열이 모두 탐색되었으면 1 아니면 0
	cout << (idx == n) << '\n';
}