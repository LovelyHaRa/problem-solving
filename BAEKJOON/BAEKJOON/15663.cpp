#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> a, selected, check;
void permutation(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << selected[i] << ' ';
		cout << '\n';
		return;
	}
	vector<int> visited(10001); // 값이 방문되었는지 여부를 파악
	for (int i = 0; i < n; i++)
	{
		// 수열 값 자체 중복여부와 수열 위치의 중복여부를 동시에 판단
		if (visited[a[i]] || check[i]) continue;
		else
		{
			visited[a[i]] = 1; // 값 방문 체크
			selected[cnt] = a[i]; // 순열 저장
			check[i] = 1; // 수열 위치 체크
			permutation(cnt + 1);
			check[i] = 0; // 수열 위치 체크 해제
		}
	}
	
}

int main(void)
{	
	cin >> n >> m;
	a.resize(n);
	selected.resize(m);
	check.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	permutation(0);
}