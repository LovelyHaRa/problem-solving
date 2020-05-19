#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int concat(const vector<int>& lengths)
{
	priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 우선수위큐 사용
	// 큐에 데이터 삽입
	for (int i = 0; i < lengths.size(); i++)
		pq.push(lengths[i]);
	int ret = 0;
	while (pq.size() > 1)
	{
		// 최소값 두개 꺼내기
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();
		// 더해서 다시 넣기
		pq.push(min1 + min2);
		// 더한 값 누적
		ret += min1 + min2;
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> lengths(n);
		for (int i = 0; i < n; i++)
			cin >> lengths[i];
		cout << concat(lengths) << '\n';
	}
}