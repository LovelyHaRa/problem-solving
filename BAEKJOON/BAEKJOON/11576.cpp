#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> k(m);
	for (int i = 0; i < m; i++)
		cin >> k[i];
	int res = 0;
	int t = 1;
	// 1. 주어진 수를 10진수로 변환
	for (int i = k.size() - 1; i >= 0; i--)
	{
		res += t * k[i];
		t *= a;
	}
	// 2. 10진수로 변환된 수를 B진수로 변환
	vector<int> kk;
	while (res > 0)
	{
		kk.push_back(res%b);
		res /= b;
	}
	// 3. 출력
	for (auto it = kk.rbegin(); it != kk.rend(); it++)
		cout << *it << ' ';
}