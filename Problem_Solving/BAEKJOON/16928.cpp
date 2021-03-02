#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	// 밤, 사다리 구분없이 map으로 저장
	map<int, int> laddersnake;
	for (int i = 0; i < n + m; i++)
	{
		int key, value;
		cin >> key >> value;
		laddersnake[key] = value;
	}
	// 방문 여부
	bool visited[101] = { false, };
	// 초기 큐 생성
	queue<int> q;
	q.push(1);
	int moveCnt = 0; // 이동 횟수
	// BFS 탐색
	while (!q.empty())
	{
		// 현재 이동 횟수에서 다음으로 이동할 수 있는 모든 경우의 수
		int turnSize = q.size();
		// 모든 경우 탐색
		while (turnSize--)
		{
			// 큐에서 추출
			int cur = q.front();
			q.pop();
			// 목표칸인 100번에 도착하면 출력하고 종료
			if (cur == 100)
			{
				cout << moveCnt << '\n';
				return 0;
			}
			// 주사위는 1부터 6까지 가능
			for (int i = 1; i <= 6; i++)
			{
				int next = cur + i; // 주사위 값 더하기
				// 뱀 또는 사다리를 만났을 경우
				if (laddersnake.find(next) != laddersnake.end())
					next = laddersnake[next]; // 칸 번호 갱신
				// 방문 여부 확인
				if (!visited[next])
				{
					visited[next] = 1; // 방문 체크
					q.push(next); // 큐에 삽입
				}
			}
		}
		moveCnt++; // 이동 횟수 증가
	}
}
