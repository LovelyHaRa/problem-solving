#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> cache;

int min(int a, int b) { return a < b ? a : b; }

// k를 제곱수의 합으로 표현할 수 있는 제곱수의 개수를 구한다
int countSum(int k)
{
	// 기저 사례: k==1
	if (k == 1) return 1;
	// 메모이제이션
	int& ret = cache[k];
	if (ret != -1) return ret;
	ret = 100001; // 최솟값 저장을 위한 초기값 세팅
	double t = sqrt((double)k); // 제곱근 값 구하기
	if (t == ceil(t)) return ret = 1; // k가 제곱수인지 판별
	else
	{
		// k 이하 가능한 모든 제곱수 탐색( 12의 경우 (4+4+4) < (9+1+1+1) )
		// 점화식 countSum(k)=count(i^2)+count(k-i^2) (i: 1~t)
		for (int i = (int)t; i > 0; i--)
			ret = min(ret, countSum(pow(i, 2)) + countSum(k - pow(i, 2))); // 최솟값 갱신
	}
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	cache.resize(n + 1, -1);
	cout << countSum(n);
}
