#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> visited(100001, -1); // visited[x] = x위치의 이전 위치를 저장
	int sec = 0; // 걸린 시간
	// 초기 큐 세팅
	visited[n] = n;
	q.push(n);
	// BFS 탐색
	while (!q.empty())
	{
		// 현재 큐 사이즈만큼 큐에서 꺼내고, 모두 꺼내면 sec 증가
		int curSize = q.size();
		while (curSize--)
		{
			// 큐에서 추출
			int x = q.front();
			q.pop();
			// 추출된 값이 도착지점이면
			if (x == k)
			{
				cout << sec << '\n'; // 걸린 시간 출력
				stack<int> route; // 경로를 스택으로 저장
				int r = k; // 갱신된 경로를 저장하는 변수
				while (r != n)
				{
					route.push(r); // 경로를 스택에 쌓음
					r = visited[r]; // 경로 갱신
				}
				route.push(n); // 출발 지점 스택에 저장
				// 경로를 스택에서 뽑아 출력
				while (!route.empty())
				{
					cout << route.top() << ' ';
					route.pop();
				}
				cout << '\n';
				return 0; // 프로그램 종료
			}
			// 갈 수 있는 위치를 모두 탐색
			for (int next : {x - 1, x + 1, x * 2})
			{
				// 범위 안에 들고 방문되지 않았더라면
				if (next >= 0 && next <= 100000 && visited[next] == -1)
				{
					visited[next] = x; // 경로 갱신
					q.push(next); // 큐애 삽입
				}
			}
		}
		sec++; // 시간 증가
	}
}