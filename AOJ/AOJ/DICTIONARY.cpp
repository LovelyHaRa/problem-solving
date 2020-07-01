#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 그래프 표현
vector<vector<int>> adj;
// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다
void makeGraph(const vector<string>& words)
{
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++)
	{
		int i = j - 1, len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; k++)
			// word[i]가 word[j]를 한글자씩 비교한다
			// 다르면 해당 알파벳을 방향그래프에 표현한다
			if (words[i][k] != words[j][k])
			{
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1;
				break;
			}
	}
}

vector<int> seen, order;
void dfs(int here)
{
	seen[here] = 1;
	for (int there = 0; there < adj.size(); there++)
		if (adj[here][there] && !seen[there])
			dfs(there);
	order.push_back(here); // 위상 정렬을 위한 체크
}
// 주어진 그래프를 위상 정렬한 결과를 반홚나다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다
vector<int> topologicalSort()
{
	int n = adj.size();
	seen = vector<int>(n, 0);
	order.clear();
	// 모든 알파벳에 대해 DFS 탐색
	for (int i = 0; i < n; i++) if (!seen[i]) dfs(i);
	// 탐색 결과 뒤집기(위상 정렬 결과)
	reverse(order.begin(), order.end());
	// DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (adj[order[j]][order[i]])
				return vector<int>();
	// 없는 경우라면 위상 정렬 결과 반환
	return order;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++)
			cin >> words[i];
		makeGraph(words);
		vector<int> res = topologicalSort();
		if (res.empty()) cout << "INVALID HYPOTHESIS\n";
		else
		{
			for (int i = 0; i < res.size(); i++)
				cout << (char)(res[i] + 'a');
			cout << '\n';
		}
	}
}