#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--)
	{
		int x;
		cin >> x;
		if (!x)
		{
			cout << (!pq.empty() ? pq.top() : 0) << '\n';
			if (!pq.empty()) pq.pop();
			continue;
		}
		pq.push(x);
	}
}
