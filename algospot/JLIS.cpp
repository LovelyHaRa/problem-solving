#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int n, m;
vector<int>A, B; // 수열
vector<vector<int>> cache; // 캐싱
const long long NEGINF = numeric_limits<long long>::min(); // 64비트 최소값

long long max(long long a, long long b) { return a > b ? a : b; }
int jlis(int indexA, int indexB)
{
	// 메모이제이션
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	// 카운트는 A, B 시작지점을 반드시 포함하므로 2부터 시작
	ret = 2;
	// a, b 중 최대값을 구함, -1일 때 -INF값을 저장
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]); 
	long long maxElement = max(a, b);
	// A 수열 중에서 증가 수열을 재귀 탐색한다.
	for (int i = indexA + 1; i < n; i++)
		if (maxElement < A[i]) ret = max(ret, jlis(i, indexB) + 1);
	// B 수열 중에서 증가 수열을 재귀 탐색한다.
	for (int i = indexB + 1; i < m; i++)
		if (maxElement < B[i]) ret = max(ret, jlis(indexA, i) + 1);
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		A.resize(n);
		B.resize(m);
		cache.resize(n + 1, vector<int>(m + 1, -1)); // -1 인덱스를 사용할 것이므로 size+1
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		cout << jlis(-1, -1) - 2 << '\n'; // -1 부터 시작했으므로 구한 값에서 -2 해줘야 한다.
		A.clear();
		B.clear();
		cache.clear();
	}
}
