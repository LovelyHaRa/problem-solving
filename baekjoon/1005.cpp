#include<iostream> // 입출력 사용
#include<vector> // 배열 백터 사용
#include<queue> // 자료구조 큐 사용
#include<algorithm> //max 사용

using namespace std;

int main(void)
{
	int T; //테스트케이스
	cin >> T;
	while (T > 0)
	{
		int n, k; // 정점, 간선개수
		cin >> n >> k;
		vector<vector<int>> graph; // 방향그래프
		queue<int> que; // 위상 큐
		vector<int> count; // 선행 연결 개수
		vector<int> d; // 건설비용
		vector<int> res; // 해당 정점 최대비용
		graph.resize(n + 1);
		count.resize(n + 1);
		d.resize(n + 1);
		res.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			count[y]++;
		}
		int w; // 특정 건물
		cin >> w;
		// 위상정렬 이용
		// 선행 연결 개수가 0인 정점을 큐에 넣어 초기 세팅함
		for (int i = 1; i <= n; i++)
		{
			if (!count[i])
				que.push(i);
		}
		while (count[w] != 0)
		{
			// 큐에서 정점을 꺼낸다.
			int v = que.front();
			que.pop();
			// 정점의 최대 건설비용을 갱신한다.
			for (int next : graph[v])
			{
				res[next] = max(res[next], res[v] + d[v]);
				if (--count[next] == 0) que.push(next);
			}
		}
		cout << res[w] + d[w] << endl; // 특정건물의 건설비용을 추가하여 출력한다.
		T--;
	}
}
