#include<iostream>
#include<queue>
#include<string>

using namespace std;

// bfs로 관리될 구슬 정보
struct balls
{
	// 이동횟수, 빨간 구슬 좌표, 파란 구슬 좌표
	int cnt, rx, ry, bx, by;
};

int board[10][10]; // 보드, 0: 벽, 1: 비어있음, 2: 구멍
bool visited[10][10][10][10]; // visited(x,y,z,w): 빨간 구슬 좌표, 파란 구슬 좌표 방문여부
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 증가량

// 벽이나 구멍을 만날 때 까지 d방향으로 움직이기
void moveBall(int &x, int &y, int d)
{
	while (board[x+dx[d]][y+dy[d]])
	{
		x += dx[d], y += dy[d];
		if (board[x][y] == 2) break;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	// 빨간 구슬, 파란 구슬, 구멍 좌표
	pair<int, int> red, blue, hole;
	// 보드 구축
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			// 입력받은 보드 정보를 숫자로 바꿔 넣기
			switch (s[j])
			{
			case '#': board[i][j] = 0; break; // 벽
			case '.': board[i][j] = 1; break; // 비어있음
			case 'O': board[i][j] = 2; hole = make_pair(i, j); break; // 구멍
			case 'R': board[i][j] = 1; red = make_pair(i, j); break; // 빨간 구슬
			case 'B': board[i][j] = 1; blue = make_pair(i, j); break; // 파란 구슬
			}
		}
	}
	int res = -1; // 결과
	// 초기 큐 세팅
	queue<balls> q;
	q.push({ 0,red.first,red.second,blue.first,blue.second });
	visited[red.first][red.second][blue.first][blue.second] = 1;
	// BFS 탐색
	while (!q.empty())
	{
		// 큐에서 추출
		balls cur = q.front();
		q.pop();
		// 1. 10회를 초과하면 탐색 중지
		if (cur.cnt > 10)
			break;
		// 2. 빨간 구슬이 구멍에 들어가면 결과 저장 후 탐색 종료
		if (make_pair(cur.rx, cur.ry) == hole)
		{
			res = cur.cnt;
			break;
		}
		// 3. 상하좌우 시뮬레이션
		for (int i = 0; i < 4; i++)
		{
			// 구슬 움직이기
			red = make_pair(cur.rx, cur.ry);
			blue = make_pair(cur.bx, cur.by);
			moveBall(red.first, red.second, i);
			moveBall(blue.first, blue.second, i);

			if (blue == hole) continue; // 파란 구슬이 구멍에 빠지면 건너뛰기

			// 구슬이 움직인 뒤 서로 같은 위치에 있으면
			if (red == blue)
			{
				// 초기 위치관계를 파악 해 구슬 위치 재조정
				switch (i)
				{
				case 0: cur.rx > cur.bx ? red.first++ : blue.first++; break;
				case 1: cur.ry > cur.by ? red.second++ : blue.second++; break;
				case 2: cur.ry < cur.by ? red.second-- : blue.second--; break;
				case 3: cur.rx < cur.bx ? red.first-- : blue.first--; break;
				}
			}
			// 방문 여부를 확인 뒤 큐에 추가
			if (!visited[red.first][red.second][blue.first][blue.second])
			{
				visited[red.first][red.second][blue.first][blue.second] = 1;
				q.push({ cur.cnt + 1, red.first,red.second,blue.first,blue.second });
			}
		}
	}
	cout << res << '\n';
}
