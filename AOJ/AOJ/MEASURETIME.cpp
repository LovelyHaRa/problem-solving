#include<iostream>
#include<vector>
#include "fenwicktree.h"

using namespace std;

// 옮겨진 횟수의 누적합을 반환한다
long long countMoves(const vector<int>& a)
{
	// 값을 카운팅하는 팬윅트리
	fenwick_tree<int> tree(1000000);
	long long ret = 0; // 누적합
	for (int i = 0; i < a.size(); i++)
	{
		// a[i]보다 더 큰값의 개수를 누적한다
		ret += tree.sum(999999) - tree.sum(a[i]);
		tree.add(a[i], 1); // 현재 수를 팬윅트리에 카운팅한다
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << countMoves(a) << '\n';
	}
}