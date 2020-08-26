#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	do
	{
		vector<int> t; // 임시 수열
		t.push_back(a[0]);
		int i;
		// m개만큼 추가
		for (i = 1; i < m; i++)
		{
			// 오름차순을 만족하면 저장
			if (t.back() < a[i])
				t.push_back(a[i]);
			else
				break;
		}
		// 반복문이 끝까지 수행되면 조건을 충족한 수열
		if (i == m)
		{
			for (int i = 0; i < t.size(); i++)
				cout << t[i] << ' ';
			cout << '\n';
		}
		reverse(a.begin() + m, a.end()); // 나머지 m개 건너뛰기
	} while (next_permutation(a.begin(), a.end()));
}