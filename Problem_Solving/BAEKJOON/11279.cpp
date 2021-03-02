#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> pq;
	while (n--)
	{
		int x;
		cin >> x;
		if (!x)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << "0\n";
			continue;
		}
		pq.push(x);
	}
}