#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int n;
vector<int> m, e;

int heat()
{
	vector<pair<int, int>> order; // (-먹는시간, 인덱스)를 쌍으로 가지는배열
	// -e[i] 값을 넣어줌으로써 자연스럽게 역순 정렬
	for (int i = 0; i < n; i++)
		order.push_back(make_pair(-e[i], i));
	sort(order.begin(), order.end()); // 오름차순 정렬(-값이므로 자연스럽게 내림차순 정렬)
	int ret = 0, beginEat = 0; // 최대값, 먹는시간
	// 시뮬레이션
	for (int i = 0; i < n; i++)
	{
		int box = order[i].second; // 가장 먹는시간이 긴 도시락 선택
		beginEat += m[box]; // 데우고
		 // 총 시간 = 모든도시락을 전자레인지에 돌리는 시간 + 먹는시간이 가장 긴 도시락 한개
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		m.resize(n);
		e.resize(n);
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> e[i];
		cout << heat() << '\n';
	}
}