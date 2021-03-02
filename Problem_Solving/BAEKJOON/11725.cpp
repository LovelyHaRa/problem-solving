#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1); // 트리를 인접 리스트로 표현
	vector<int> parent(n + 1); // parent[x]: x의 부모 노드
	vector<bool> check(n + 1); // 노드 중복 탐색 방지 배열
	// 인접 리스트 구성
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// 초기 큐 세팅
	queue<int> q;
	q.push(1);
	// BFS 탐색
	while (!q.empty())
	{
		// 노드 추출
		int here = q.front();
		q.pop();
		// 연결된 노드 탐색
		for (int there : adj[here])
		{
			// 미방문 시
			if (!check[there])
			{
				check[there] = true; // 방문 체크
				parent[there] = here; // here노드는 there 노드의 부모
				q.push(there); // 큐에 노드 삽입
			}
		}
	}
	// 출력
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}
