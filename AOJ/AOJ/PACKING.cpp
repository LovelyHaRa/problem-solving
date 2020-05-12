#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, capacity; // 물품 개수, 무계 한계
vector<vector<int>> cache; // 캐시
vector<int> volume, need; // 무게 리스트, 절박도 리스트
vector<string> name; // 물품 이름 리스트

int max(int a, int b) { return a > b ? a : b; }

int pack(int capacity, int item)
{
	// 기저 사례: 아이템을 모두 탐색했을 때
	if (item == n) return 0;
	// 메모이제이션
	int& ret = cache[capacity][item];
	if (ret != -1)return ret;
	// 1. 현재 아이템을 선택하지 않았을 때
	ret = pack(capacity, item + 1);
	// 2. 현재 아이템을 선택했을 때
	if (capacity >= volume[item])
		// 1과 비교하여 최대값 저장
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked)
{
	// 기저 사례: 아이템을 모두 탐색했을 때
	if (item == n) return;
	// 현재 아이템을 선택하지 않은 경우: 무시하고 다음 아이템 탐색
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	// 현재 아이템을 선택한 경우
	else
	{
		picked.push_back(name[item]); // 아이템 저장
		// 다음 아이템 탐색
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		// 입력
		cin >> n >> capacity;
		cache.resize(1001, vector<int>(n, -1));
		volume.resize(n);
		need.resize(n);
		name.resize(n);
		for (int i = 0; i < n; i++)
			cin >> name[i] >> volume[i] >> need[i];
		// 절박도 최대값 구하기
		pack(capacity, 0);
		// 선택한 아이템 리스트 만들기
		vector<string> picked;
		reconstruct(capacity, 0, picked);
		// 출력
		int cnt = picked.size();
		cout << pack(capacity, 0) << ' ' << cnt << '\n';
		for (int i = 0; i < cnt; i++)
			cout << picked[i] << '\n';
		// 초기화
		cache.clear();
		volume.clear();
		need.clear();
		name.clear();
	}
}