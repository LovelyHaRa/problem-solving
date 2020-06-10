#include<iostream>
#include<vector>
#include"trip.h"

using namespace std;

int n;
vector<int> shifted, a;

void solve()
{
	// 트립 생성
	TripNode<int>* candidates = NULL;
	for (int i = 0; i < n; i++)
		candidates = insert(candidates, new TripNode<int>(i + 1));
	// 역순으로 A[i]를 저장
	for (int i = n - 1; i >= 0; i--)
	{
		int larger = shifted[i]; // A[i]보다 큰 수가 larger개 있다
		// i+1-larger번째 노드를 찾는다
		TripNode<int>* k = kth(candidates, i + 1 - larger);
		a[i] = k->key; // 노드를 저장한다
		// 저장된 노드를 삭제한다
		candidates = erase(candidates, k->key);
	}
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
		cin >> n;
		a.resize(n);
		shifted.resize(n);
		for (int i = 0; i < n; i++)
			cin >> shifted[i];
		solve();
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
		a.clear();
		shifted.clear();
	}
}