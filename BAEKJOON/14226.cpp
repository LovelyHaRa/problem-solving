#include<iostream>
#include<queue>

using namespace std;

// 입력된 이모티콘 길이, 클립보드 사이즈, 입력될 때의 시간
struct emoticon {
	int length, clipboard, time;
};

int main(void)
{
	int s;
	cin >> s;
	queue<emoticon> q;
	// visited[x][y] 길이가 x이고 클립보드 사이즈가 y일 때의 방문 여부
	bool visited[1001][1001] = { false, };
	// 초기 큐
	q.push({1,0,0});
	visited[1][0] = 1;
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		int k = q.front().length; // 길이
		int c = q.front().clipboard; // 클립보드 사이즈
		int sec = q.front().time; // 시간
		q.pop();
		// 길이가 목표와 일치하면
		if (k == s)
		{
			// 출력 후 리턴
			cout << sec << '\n';
			return 0;
		}
		// 길이가 범위 내이면
		if (k > 0 && k <= 1000)
		{
			// 1. 클립보드에 복사
			if (!visited[k][k])
			{
				visited[k][k] = 1;
				q.push({ k,k,sec + 1 });
			}
			// 2. 클립보드 내용을 붙여 넣기
			if (k + c <= 1000 && !visited[k + c][c])
			{
				visited[k + c][c] = 1;
				q.push({ k + c,c,sec + 1 });
			}
			// 3. 내용을 하나 지우기
			if (!visited[k - 1][c])
			{
				visited[k - 1][c] = 1;
				q.push({ k - 1,c,sec + 1 });
			}
		}
	}
}
