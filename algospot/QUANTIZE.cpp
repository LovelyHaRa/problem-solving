#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> A, pSum, pSqSum;
vector<vector<int>> cache;
const int INF = 1987654321;

// 부분합 구하기
void precalc()
{
	sort(A.begin(), A.end()); // 정렬
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; i++)
	{
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}

// 부분 합을 이용하여 상수 시간에 평균을 계산하는 방법
int minError(int lo, int hi)
{
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]); // 수열의 합
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]); // 수열 제곱의 합
	int m = int(0.5 + sum / (double)(hi - lo + 1)); // 평균 반올림
	int ret = sqSum - (2 * m*sum) + (m * m*(hi - lo + 1)); // 최소 오차 구하기
	return ret;
}

// 문제 변경: 주어진 수열을 s개 묶음으로 나누어 최소 오차의 합을 구하기
int quantize(int from, int parts)
{
	// 기저 사례: 모든 숫자를 다 양자화 했을 때
	if (from == n) return 0;
	// 기저 사례: 숫자는 남았는데 묶을 수 없을 때: 아주 큰 값을 반환
	if (parts == 0) return INF;
	// 메모이제이션
	int& ret = cache[from][parts];
	if (ret != -1) return ret;
	ret = INF; // 최솟값을 구하기 위해 초기화
	// 조각의 길이를 변화시키며 최소치를 찾는다
	for (int partSize = 1; from + partSize <= n; partSize++)
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int s;
		cin >> n >> s;
		A.resize(n);
		pSum.resize(n);
		pSqSum.resize(n);
		cache.resize(n, vector<int>(s + 1, -1));
		for (int i = 0; i < n; i++)
			cin >> A[i];
		precalc();
		cout << quantize(0, s) << '\n';
		A.clear();
		pSum.clear();
		pSqSum.clear();
		cache.clear();
	}
}
