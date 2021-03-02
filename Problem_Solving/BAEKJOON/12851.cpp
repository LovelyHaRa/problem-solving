#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q; // 현재 지점, 걸린 시간을 페어로 저장할 수 있는 큐
	vector<bool> visited(100001); // 방문 여부 체크
	vector<int> cnt(100001);// cnt[sec] = sec초일 때, k지점에 도착한 횟수
	// 초기 큐
	q.push(make_pair(n, 0));
	int res = 100001; // 걸린 시간의 최솟값(출력 대상)
	// BFS 탐색
	while (!q.empty())
	{
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();
		visited[x] = true; // 큐에서 제거할 때 방문 체크
		// 목표지점에 도착했을 시
		if (x == k)
		{
			cnt[sec]++; // 카운팅
			res = min(res, sec); // 걸린시간 최솟값 갱신
		}
		// 3가지 이동 할 수 있는 경우에 대해
		for (int next : {x - 1, x + 1, x * 2})
		{
			// 범위 내이고 방문된 적이 없다면
			if (next >= 0 && next <= 100000 && !visited[next])
				q.push(make_pair(next, sec + 1)); // 큐에 이동 후의 값과 시간을 증가시켜 삽입
		}
	}
	cout << res << '\n' << cnt[res] << '\n'; // 시간의 최솟값과 그에 해당하는 카운팅 값을 출력
}
