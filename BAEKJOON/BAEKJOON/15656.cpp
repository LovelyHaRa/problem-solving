#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> a, selected;

void permutation(int cnt)
{
	// 기저사례: cnt==m
	if (cnt == m)
	{
		// 출력
		for (int i = 0; i < m; i++)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	// 중복 순열이므로 모든 경우를 DFS
	for (int i = 0; i < n; i++)
	{
		selected[cnt] = a[i];
		permutation(cnt + 1);
	}
	return;
}

int main(void)
{
	cin >> n >> m;
	a.resize(n);
	selected.resize(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// 오름차순 정렬
	sort(a.begin(), a.end());
	permutation(0);
}