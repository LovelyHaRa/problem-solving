#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<bool> check(100001);
	int sec = 0;
	// 초기 큐 생성
	q.push(n);
	check[n] = true;
	// BFS 탐색
	while (!q.empty())
	{
		int curSize = q.size(); // 해당 시간에 이동할 수 있는 위치의 수
		// 위치 수만큼 반복
		while (curSize-- > 0)
		{
			int x = q.front();
			q.pop();
			// 동생의 위치일 경우 리턴
			if (x == k)
			{
				cout << sec << '\n';
				return 0;
			}
			// x-1 이동
			if (x - 1 >= 0 && !check[x - 1])
			{
				check[x - 1] = true;
				q.push(x - 1);
			}
			// x+1 이동
			if (x + 1 <= 100000 && !check[x + 1])
			{
				check[x + 1] = true;
				q.push(x + 1);
			}
			// x*2이동
			if (x * 2 <= 100000 && !check[x * 2])
			{
				check[x * 2] = true;
				q.push(x * 2);
			}
		}
		sec++; // 시간 증가
	}
}