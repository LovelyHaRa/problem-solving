#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1, vector<int>()); // 인접 리스트로 표현(인접 행렬은 메모리 초과)
	// 입력
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		cin >> ans[i];
	vector<int> check(n + 1); // 방문 여부
	int pos = 1; // 방문 순서 인덱스
	// 초기 큐 생성
	queue<int> q;
	q.push(1);
	check[1] = 1;
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 꺼내기
		int here = q.front();
		q.pop();
		// 기저 사례: pos<n
		while (pos<n)
		{
			int there = ans[pos];
			int i;
			// 방문 순서를 참조하여 연결된 정점 모두 큐에 넣기
			for (i = 0; i < adj[here].size(); i++)
			{
				if (adj[here][i] == there && !check[there])
				{
					check[there] = 1;
					q.push(there);
					pos++; // 방문 순서 인덱스 증가
					break;
				}
			}
			// 연결된 정점을 모두 큐에 넣었으면 반복문 탈출
			if (i == adj[here].size()) break;
		}
	}
	cout << (pos == n) << '\n'; // BFS 탐색 중방문 순서 배열을 모두 참조했다면 1, 아니면 0
}