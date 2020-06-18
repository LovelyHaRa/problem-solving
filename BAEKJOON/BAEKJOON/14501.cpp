#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> t, p;
int res = 0; // 최대값

int max(int a, int b) { return a > b ? a : b; }

// 시작지점과 지금까지의 비용이 주어졌을 때
// 시작지점을 기준으로 상담 가능한 모든 경우를 탐색한다
void leave(int start, int sum)
{
	// 다음 상담 가능한 시작점을 저장한다
	int next = start + t[start] - 1;
	// 기저 사례: 다음 지점이 n 이상일 경우
	if (next >= n)
	{
		// 마지막 일을 못하는 경우
		if (next > n)
			res = max(res, sum - p[start]); // 이전 일 취소
		// 마지막 일을 할 수 있는 경우
		else
			res = max(res, sum);
		return;
	}
	// 다음 상담 가능한 지점부터 탐색한다
	for (int i = next + 1; i <= n; i++)
		leave(i, sum + p[i]);
}

int main(void)
{
	cin >> n;
	t.resize(n + 1);
	p.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	for (int i = 1; i <= n; i++)
		leave(i, p[i]);
	cout << res << '\n';
}