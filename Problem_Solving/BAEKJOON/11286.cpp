#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	// 절댓값, 원래값을 쌍으로 가지는 pq 생성
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	while (n--)
	{
		int x;
		cin >> x;
		// 0일 때
		if (!x)
		{
			// 큐에서 추출
			cout << (!pq.empty() ? pq.top().second : x) << '\n';
			if (!pq.empty()) pq.pop();
		}
		// 0이 아닐 때
		else
			pq.push({ abs(x),x }); // 큐에 삽입
	}
}
