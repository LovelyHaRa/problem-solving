#include<iostream>
#include<string>

using namespace std;

string board[20];
int r, c, dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 };

int max(int a, int b) { return a > b ? a : b; }

// (x, y) 위치에서 4방향으로 이동한다
// 비트마스크를 이용하여 알파벳을 체크한다(26자리, MSB: Z, LSB, A)
int move(int x, int y, int check)
{
	int ret = 0; // 현재 지점에서의 이동 횟수
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i]; // 다음 위치 계산
		// 범위를 벗어나거나 이미 체크한 알파벳이면 무시한다
		if (nx < 0 || nx >= r || ny < 0 || ny >= c || check & 1 << board[nx][ny] - 65) continue;
		// 4방향 중 가장 멀리 갈 수 있는 횟수를 구한다
		ret = max(ret, move(nx, ny, check | 1 << board[nx][ny] - 65));
	}
	return ++ret; // 이 지점을 방문 했으므로 이동 횟수를 1 추가한다
}

int main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> board[i];
	cout << move(0, 0, 1 << board[0][0] - 65) << '\n';
}
