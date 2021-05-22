// 수학
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 팩토리얼의 2와 5의 개수
pair<long long, long long> countZero(long long k)
{
	int two = 0, five = 0;
	// 제곱 수만큼 추가되는것을 고려
	for (long long i = 2; i <= k; i *= 2)
		two += k / i;
	for (long long i = 5; i <= k; i *= 5)
		five += k / i;
	
	return { two, five };
}

int main(void)
{
	long long n, m;
	cin >> n >> m;
	// 1. n!의 2와 5의 개수를 구한다.
	// 2. n! 대신 (n-m)!에 대해서 1을 수행
	// 3. n! 대신 m!에 대해서 1을 수행
	// 4. 2의 개수와 5의 개수에 대해 1-2-3 을 했을 떄의 결과가 최소인 것 출력
	vector<pair<long long, long long>>res(3);
	
	res[0] = countZero(n); // 1
	res[1] = countZero(n-m); // 2
	res[2] = countZero(m); // 3
	// 4
	cout << min((res[0].first - res[1].first - res[2].first),
		(res[0].second - res[1].second - res[2].second)) << '\n';
}
