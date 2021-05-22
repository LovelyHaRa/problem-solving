#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		bool visited[10000] = { false, }; // 방문 여부
		queue<pair<int, string>> q; // 숫자, 지금까지 입력된 명령어를 페어로 하는 큐 생성
		// 초기 큐 생성
		q.push(make_pair(a, ""));
		visited[a] = 1;
		// BFS 탐색
		while (!q.empty())
		{
			// 큐에서 추출
			int curNum = q.front().first;
			string curCmd = q.front().second;
			q.pop();
			// 목표 숫자에 도달하면
			if (curNum == b) {
				//출력 후 탐색 종료
				cout << curCmd << '\n';
				break;
			}
			// 다음 번호 계산
			int next = curNum * 2 % 10000;
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'D'));
			}
			next = curNum - 1 < 0 ? 9999 : curNum - 1;
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'S'));
			}
			next = (curNum % 1000) * 10 + curNum / 1000; // 왼쪽 시프트
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'L'));
			}
			next = curNum % 10 * 1000 + curNum / 10; // 오른쪽 시프트
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(make_pair(next, curCmd + 'R'));
			}
		}
	}
}
