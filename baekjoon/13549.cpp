#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q; // 위치, 해당 위치까지 걸린 시간을 페어로 저장하는 큐
	vector<bool> visited(100001); // 방문 여부
	// 초기 큐 생성
	q.push(make_pair(n, 0));
	visited[n] = n;
	int res=100001;
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int x = q.front().first; // 현재 위치
		int sec = q.front().second; // 걸린 시간
		q.pop();
		// 해당 위치까지 도달하는 모든 과정을 체크하고 걸린 시간의 최솟값을 얻기 위해
		// 방문 체크를 큐에서 꺼낼 때 한다
		visited[x] = 1;
		// 목표 위치에 도달하면
		if (x == k)
		{
			res = min(res, sec); // 최솟값 갱신
			continue;
		}
		// 왼쪽, 오른쪽 이동
		for (int next : {x - 1, x + 1})
		{
			// 범위 내이고 방문되지 않았다면
			if (next >= 0 && next <= 100000 && !visited[next])
				q.push(make_pair(next, sec + 1)); // 큐에 삽입
		}
		// 순간이동
		// 범위 내이고 방문되지 않았다면
		if (x * 2 <= 100000 && !visited[x * 2])
			q.push(make_pair(x * 2, sec)); // 순간이동은 시간 소요 안함
	}
	cout << res << '\n';
}
