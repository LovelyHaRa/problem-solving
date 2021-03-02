#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> price, pref, cache;

int max(int a, int b) { return a > b ? a : b; }

// 재귀적 동적 계획법 (해결 불가, 메모리 초과)
//int sushi(int budget)
//{
//	int& ret = cache[budget];
//	if (ret != -1) return ret;
//	ret = 0;
//	for (int dish = 0; dish < n; dish++)
//	{
//		if (budget < price[dish]) continue;
//		ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
//	}
//	return ret;
//}

int sushi()
{
	int ret = 0;
	cache[0] = 0;
	for (int budget = 1; budget <= m; budget++)
	{
		int cand = 0;
		for (int dish = 0; dish < n; dish++)
		{
			if (budget >= price[dish])
				cand = max(cand, cache[(budget - price[dish]) % 201] + pref[dish]);
		}
		cache[budget % 201] = cand;
		ret = max(ret, cand);
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
		price.resize(n);
		pref.resize(n);
		// 초밥의 가격이 100의 배수임을 이용
		// 자투리 가격은 의미가 없으니 모든 예산과 가격을 100으로 나눔
		// 10억->1000만
		cache.resize(201); // 캐시 사이즈도 20001 -> 201
		for (int i = 0; i < n; i++)
		{
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		m /= 100;
		cout<<sushi()<<'\n';
		price.clear();
		pref.clear();
		cache.clear();
	}
}