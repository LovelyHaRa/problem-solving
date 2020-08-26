#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> a, selected;

// 순열을 탐색한다
void permutation(int cnt)
{
	// 기저 사례: cnt==m
	if (cnt == m)
	{
		// 출력
		for (int i = 0; i < m; i++)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	// 주소적 중복은 허용, 숫자 중복은 비허용
	vector<int> visited(10001); // 숫자 중복 체크
	for (int i = 0; i < n; i++)
	{
		if (visited[a[i]]) continue;
		selected[cnt] = a[i];
		visited[a[i]] = 1; // 방문 체크
		permutation(cnt + 1);
	}
}

int main(void)
{
	cin >> n >> m;
	a.resize(n);
	selected.resize(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	permutation(0);
}