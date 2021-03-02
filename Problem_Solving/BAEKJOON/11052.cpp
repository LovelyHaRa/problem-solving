#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int n;
vector<int> p, cache;

// pick개의 카드를 선택했을 때 최대 가격을 리턴
int card(int pick)
{
	// 기저 사례: 선택할 카드가 없는 경우
	if (!pick) return 0;
	// 메모이제이션
	int& ret = cache[pick];
	if (ret != -1) return ret;
	ret = 0; // 최소값은 0원
	// 1부터 pick개까지 반복
	for (int j = 1; j <= pick; j++)
		// j개의 카드를 선택하고 나머지를 선택한 경우를 더한것을 비교하여 최대값 갱신
		ret = max(ret, p[j] + card(pick - j));
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