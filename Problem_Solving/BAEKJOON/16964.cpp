#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> adj; // 인접 리스트 구현
vector<bool> check; // 방문 여부
vector<int> ans; // 정답 인풋
vector<int> order; // 방문 순서 인덱스
vector<int> res; // dfs 수행 결과

// dfs 탐색
void dfs(int x)
{
	// 탐색 체크
	check[x] = 1;
	res.push_back(x); // 탐색 결과 배열에 넣기
	// 다음 노드 탐색
	for (int y = 0; y < adj[x].size(); y++)
	{
		int next = adj[x][y];
		if (!check[next]) dfs(next);
	}
}

bool compare(int a, int b)
{
	return order[a] < order[b];
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
		a--; b--; // 정점을 0부터 시작
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans.resize(n);
	order.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ans[i];
		ans[i]--; // 정점을 0부터 시작
		order[ans[i]] = i; // 기록된 정점의 순서를 저장
	}
	// 인접 리스트의 정점을 기록된 정점의 순서로 정렬
	for (int i = 0; i < n; i++)
		sort(adj[i].begin(), adj[i].end(), compare);
	// 1부터 dfs 탐색
	dfs(0);
	// 정답배열이 모두 탐색되었으면 1 아니면 0
	cout << (res == ans) << '\n';
}