#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> p, cache;

int min(int a, int b) { return a < b ? a : b; }

// pick개의 카드를 구매할 수 있는 최소 비용을 반환
int card(int pick)
{
	// 기저 사례: 카드를 선택할 수 없는 경우
	if (pick == 0) return 0;
	// 메모이제이션
	int& ret = cache[pick];
	if (ret != -1) return ret;
	ret = 987654321; // 최소값을 저장하기 위한 초기 세팅
	// 1~pick개의 카드 구매
	for (int buy = 1; buy <= pick; buy++)
		ret = min(ret, p[buy] + card(pick - buy)); // 나머지 카드를 재귀 반복
	return ret;
}

int main(void)
{
	cin >> n;
	p.resize(n + 1);
	cache.resize(n + 1, -1);
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	cout << card(n);
}