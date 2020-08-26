#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m; // 가로, 세로의 길이
vector<string> board(20); // 보드 정보
pair<int, int> coin[2]; // 보드에 위치한 두 동전의 x, y 좌표 페어
int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 이동 증가량

// (x, y)가 범위 내에 속해 있는지 판별
bool isOutRange(int x, int y)
{
	return (x<0 || x>=n || y < 0 || y >= m);
}

// (x, y)가 벽에 위치해있는지 확인
bool isWall(int x, int y) { return !isOutRange(x, y) && board[x][y] == '#'; }

// 두 동전 c1, c2중 하나가 보드에서 떨어질 때 까지 이동
int move(pair<int, int> c1, pair<int, int> c2, int cnt)
{
	if (cnt > 10) return -1; // 기저사례 1: 횟수 10회 초과 시 -1 리턴
	// 위치값 추출
	int c1x = c1.first, c1y = c1.second, c2x = c2.first, c2y = c2.second;
	// 범위 밖(떨어졌는 지) 확인
	bool out1 = isOutRange(c1x, c1y), out2 = isOutRange(c2x, c2y);
	// 기저사례 2: 둘 다 떨어지면 불가능(-1 리턴)
	if (out1 && out2) return -1;
	// 기저사례 3: 하나만 떨어지면 이동 횟수 리턴
	if (out1 || out2) return cnt;

	int ret = -1; // 반환할 이동 횟수
	// 상하좌우 이동
	for (int i = 0; i < 4; i++)
	{
		// 동전 이동
		int c1nx = c1x + dx[i], c1ny = c1y + dy[i];
		int c2nx = c2x + dx[i], c2ny = c2y + dy[i];
		// 벽에 위치했다면 원상 복구
		if (isWall(c1nx, c1ny)) c1nx = c1x, c1ny = c1y;
		if (isWall(c2nx, c2ny)) c2nx = c2x, c2ny = c2y;
		// 다음 지점 탐색
		int next = move(make_pair(c1nx, c1ny), make_pair(c2nx, c2ny), cnt + 1);
		// 불가능 한 경우는 건너 뛰기
		if (next == -1) continue;
		// 그렇지 않다면 가능한 경우 이므로 최초/최솟값 갱신
		if (ret == -1 || ret > next) ret = next;
	}
	return ret; // 이동 횟수 반환
}

int main()
{
	cin >> n >> m;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
			if (board[i][j] == 'o')
				coin[c++] = make_pair(i, j); // 코인 저장
	}
	cout << move(coin[0], coin[1], 0) << '\n';;
}