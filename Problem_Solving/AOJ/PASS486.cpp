#include<iostream>
#include<vector>

using namespace std;

const int M = 1000 * 1000 * 10;
vector<int> factors(M + 1, 0);

// 약수 개수 구하기(단순 알고리즘)
void getFactors()
{
	for (int div = 1; div <= M; div++)
		for (int multiple = div; multiple <= M; multiple += div)
			factors[multiple]++;
}

int main(void)
{
	getFactors();
	int c;
	cin >> c;
	while (c--)
	{
		int n, lo, hi;
		cin >> n >> lo >> hi;
		int cnt = 0;
		// 범위내에 조건을 만족하면 카운팅
		for(int i=lo;i<=hi;i++)
			if (n == factors[i])
				cnt++;
		cout << cnt << '\n';
	}
}