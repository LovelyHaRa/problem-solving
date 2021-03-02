#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;
vector<int> A;

int max(int a, int b) { return a > b ? a : b; }

// 시작지점이 start일 때 최장 부분 감소 수열 길이를 반환
int lds(int start)
{
	// 메모이제이션
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1; // 길이는 무조건 1부터 시작
	for (int i = start + 1; i < n; i++)
		// 시작지점이 -1이거나 수열이 순감소할 경우
		if (start == -1 || A[start] > A[i])
			ret = max(ret, lds(i) + 1); // 길이의 최대값 갱신
	return ret; // 길이 반환
}

int main(void)
{
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cache.resize(n + 1, -1);
	cout << lds(-1) - 1 << '\n'; // -1 부터 시작했으므로 -1 감소된 값을 출력
}