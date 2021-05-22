#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
// catEat[i]: i번째 친구가 먹을 수 있는 음식의 집합
// eaters[i]: i번째 음식을 먹을 수 있는 친구의 집합
vector<vector<int>> canEat, eaters;
int best;

void search(vector<int>& edible, int chosen)
{
	// 간단한 가지치기
	if (chosen >= best) return;
	int first = 0;
	// 현재 선택된 음식들을 못먹는 사람 검색
	while (first < n && edible[first]>0) first++;
	// 기저 사례: 모든 친구가 음식을 먹을 수 있을 때
	if (first == n) {
		best = chosen; // 최적 값 저장
		return;
	}
	// 못먹는 사람이 먹을 수 있는 음식 탐색
	for (int i = 0; i < canEat[first].size(); i++)
	{
		// 음식을 먹을 수 있는지 체크
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); j++)
			edible[eaters[food][j]]++;
		search(edible, chosen + 1); // 재귀 탐색
		// 원상 복구
		for (int j = 0; j < eaters[food].size(); j++)
			edible[eaters[food][j]]--;
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		map<string,int> friends; //친구들을 인덱스로 매핑
		vector<int> edible(n, 0); // edible[i]: i번째 친구가 먹을 수 있는 음식의 개수
		for (int i = 0; i < n; i++)
		{
			string f;
			cin >> f;
			friends[f] = i; // 매핑
		}
		eaters.resize(m);
		canEat.resize(n);
		for (int i = 0; i < m; i++)
		{
			int c;
			cin >> c;
			for (int j = 0; j < c; j++)
			{
				string f;
				cin >> f;
				eaters[i].push_back(friends[f]);
				canEat[friends[f]].push_back(i);
			}
		}
		best = m;
		search(edible, 0);
		cout << best << '\n';
		canEat.clear();
		eaters.clear();
	}
}
