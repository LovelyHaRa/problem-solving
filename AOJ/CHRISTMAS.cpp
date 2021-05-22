#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
// 몇가지 방법으로 살수 있는지 반환
int waysToBuy(const vector<int>& psum, int k)
{
	const int mod = 20091101;
	int ret = 0;
	// 선물이 가능하려면 psum[H-1]=psum[T]이어야 한다 [ (psum[T]-psum[H-1]) mod k == 0 ]
	vector<long long> count(k, 0); // 부분합 카운트
	// 부분합이 같은것 끼리 묶는다
	for (int i = 0; i < psum.size(); i++)
		count[psum[i]]++;
	// 2개를 선택하면 한번의 주문이 된다
	for (int i = 0; i < k; i++)
		if (count[i] >= 2)
			// 이 값 중 두개를 선택하는 방법의 수를 더한다.
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % mod;
	return ret;
}

// 겹치지 않게 몇 번이나 살 수있는지 반환
int maxBuys(const vector<int>& psum, int k)
{
	// 첫 번째 상자부터 i번째 상자까지 고려했을 때 살 수 있는 최대 횟수
	vector<int> ret(psum.size(), 0);
	// psum이 s였던 마지막 위치
	vector<int> prev(k, -1);
	for (int i = 0; i < psum.size(); i++)
	{
		// i번째 상자를 아예 고려하지 않는 경우
		if (i > 0) ret[i] = ret[i - 1];
		else ret[i] = 0;
		// psum[i]를 전에도 본 적이 있으면, prev[psum[i]]+1 부터 여기까지 쭉 사 본다.
		int loc = prev[psum[i]];
		if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		// 현재 위치를 기록한다.
		prev[psum[i]] = i;
	}
	return ret.back();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> d(n + 1), psum(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i];
			psum[i] = (psum[i - 1] + d[i]) % k; // 부분합을 k에 대한 나머지로 저장한다
		}
		cout << waysToBuy(psum, k) << ' ';
		cout << maxBuys(psum, k) << '\n';
	}
}
