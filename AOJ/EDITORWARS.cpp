#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct BipartiteUnionFind
{
	// parent[i]=i의 부모 노드. 루트라면 i
	// rank[i]=i가 루트인 경우, i를 루트로 하는 트리의 랭크(높이)
	// emeny[i]=i가 루트인 경우, 해당 집합과 적대 관계인 집합의 루트의 번호(없으면 -1)
	// size[i]=i가 루트인 경우, 해당 집합의 크기
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1)
	{
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	// 최적화된 원소 찾기
	int find(int u)
	{
		if (parent[u] == u) return u;
		// 루트까지의 모든 경로를 갱신
		return parent[u] = find(parent[u]);
	}
	// 트리 합치기
	int merge(int u, int v)
	{
		// u나 v가 공집합인 경우 나머지 하나를 반환한다
		if (u == -1 || v == -1) return max(u, v);
		// 루트 찾기
		u = find(u);
		v = find(v);
		// 이미 둘이 같은 트리에 속한 경우
		if (u == v) return u;
		// 항상 높이가 낮은 쪽을 높은쪽의 서브트리로 포함
		if (rank[u] > rank[v]) swap(u, v);
		// 높이가 같으면 결과 트리의 높이를 1 증가
		if (rank[u] == rank[v]) rank[v]++;
		// 이제 항상 rank[v]가 더 크므로 u를 v의 자식으로 넣는다
		parent[u] = v;
		// 사이즈 갱신
		size[v] += size[u];
		return v;
	}
	// u와 v가 서로 적대하는 집합에 속한다
	bool dis(int u, int v)
	{
		// 우선 루트를 찾는다
		u = find(u); v = find(v);
		// 같은 집합에 속해있으면 모순
		if (u == v) return false;
		// 적의 적은 나의 동지
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		// 결과적으로 얻은 두 집합 또한 적대 관계로 설정
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	bool ack(int u, int v)
	{
		// 우선 루트를 찾는다
		u = find(u); v = find(v);
		// 서로 적대관계이면 모순
		if (enemy[u] == v) return false;
		// 동지의 적은 나의 적
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		// 결과적으로 얻은 두집합의 적대 관계 설정
		enemy[a] = b;
		// 두 집합 다 적대하는 집합이 없으면 b는 -1일 수도 있다.
		if (b != -1) enemy[b] = a;
		return true;
	}
};

int n, m;

// 한 파티에 올 가능성이 있는 최대 인원을 구한다
int maxParty(const BipartiteUnionFind& buf)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (buf.parent[i] == i)
		{
			int enemy = buf.enemy[i];
			// 같은 모임 쌍을 두번 세지 않기 위해, emeny<i인 경우만 센다
			// enemy==-1인 경우도 정확히 한 번씩 세게 된다.
			if (enemy > i) continue;
			int mySize = buf.size[i];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			// 두 집합 중 큰 잡합을 더한다
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		BipartiteUnionFind buf(n);
		vector<string> type(m);
		vector<int>a(m), b(m);
		for (int i = 0; i < m; i++)
			cin >> type[i] >> a[i] >> b[i];
		int i;
		for (i = 0; i < m; i++)
		{
			if (type[i][0] == 'A')
			{
				if (!buf.ack(a[i], b[i]))
				{
					cout << "CONTRADICTION AT " << i + 1 << '\n';
					break;
				}
			}
			else
			{
				if (!buf.dis(a[i], b[i]))
				{
					cout << "CONTRADICTION AT " << i + 1 << '\n';
					break;
				}
			}
		}
		if (i == m)
			cout << "MAX PARTY SIZE IS " << maxParty(buf) << '\n';
	}
}
