#include<iostream>
#include<queue>
using namespace std;
int main(void)
{
	int N, M,count=0;
	queue<int> q;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		q.push(i);
	cout << '<';
	while (!q.empty())
	{
		count++;
		if (!(count%M))
			q.size() > 1 ? cout << q.front() << ", " : cout << q.front() << '>' << endl;
		else
			q.push(q.front());
		q.pop();
	}
}
