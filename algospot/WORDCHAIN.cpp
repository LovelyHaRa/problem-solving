#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// 그래프의 인접 행렬 표현, adj[i][j]=i와 j사이의 간선의 수
vector<vector<int>> adj;
// graph[i][j]=i로 시작해서 j로 끝나는 단어의 목록
vector<string> graph[26][26];
// indegree[i]=i로 시작하는 단어의 수
// outdegree[i]=i로 끝나는 단어의 수
vector<int> indegree, outdegree;
// 그래프 생성
void makeGraph(const vector<string>& words)
{
	// 전역 변수 초기화
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	// 각 단어를 그래프와 인접행렬에 표현한다
	for (int i = 0; i < words.size(); i++)
	{
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]); // 그래프에 단어 추가
		// 인접 행렬에 표현
		adj[a][b]++;
		// 차수 갱신
		outdegree[a]++;
		indegree[b]++;
	}
}

// DFS를 이용하여 오일러 서킷 혹은 트레일을 계산한다
void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < adj.size(); there++)
		while (adj[here][there] > 0)
		{
			adj[here][there]--; // 간선을 하나 지운다
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here); // 서킷에 정점을 추가한다
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다
vector<int> getEulerTrailOrCircuit()
{
	vector<int> circuit;
	// 1. 트레일 확인
	for (int i = 0; i < 26; i++)
	{
		// 트레일 조건: 나가는 간선의 수가 들어오는 간선의 수보다 하나 더 많아야한다
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	// 2. 트레일이 아니면 서킷이므로 간선에 인접한 아무 정점에서 시작
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i])
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	return circuit;
}

// 현재 그래프의 오일러 서킷/트레일 존재 여부를 확인한다
bool checkEuler()
{
	// 예비 시작점과 끝점의 수
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++)
	{
		int delta = outdegree[i] - indegree[i];
		// 모든 정점의 차수는 -1, 1 또는 0이어야 한다
		if (delta < -1 || delta > 1) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	// 시작점과 끝점은 각 하나씩 있거나 하나도 없어야 한다
	return (plus1 == 1 && minus1 == 1) || (!plus1 && !minus1);
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
		// 오일러 서킷/트레일이 존재하지 않으면 불가능
		if (!checkEuler())
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<int> circuit = getEulerTrailOrCircuit();
		// 컴포넌트가 여러개이면 불가능
		// 모든 간선을 방문했는지 확인 필요
		if (circuit.size() != words.size() + 1)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		// 방향 그래프이므로 탐색 결과를 뒤집음
		reverse(circuit.begin(), circuit.end());
		for (int i = 1; i < circuit.size(); i++)
		{
			int a = circuit[i - 1], b = circuit[i];
			cout << graph[a][b].back() << ' ';
			graph[a][b].pop_back();
		}
		cout << '\n';
	}
}
