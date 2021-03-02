#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
vector<vector<int>> edge;
vector<bool> visit;

void DFS(int n)
{
	visit[n] = true;
	cout << n << " ";
	for (int i : edge[n])
	{
		if (visit[i]) continue;
		DFS(i);
	}
}

void BFS(int s)
{
	queue<int> q;
	visit[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int n = q.front();
		q.pop();
		cout << n << " ";
		for (int i : edge[n])
		{
			if (visit[i]) continue;
			visit[i] = true;
			q.push(i);
		}
	}

}

int main(void)
{
	int N, M, V;
	cin >> N >> M >> V;
	edge.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i=1;i<=N;i++)
		sort(edge[i].begin(), edge[i].end());
	DFS(V);
	cout << endl;
	visit.clear();
	visit.resize(N + 1);
	BFS(V);
	cout << endl;
}