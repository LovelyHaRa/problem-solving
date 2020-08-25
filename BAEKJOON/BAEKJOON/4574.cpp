#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> board, tile; // 보드, 도미노 타일
vector<int> row, col, square; // 비트 마스크로 행, 열, 사각형 숫자 중복 체크
int t = 1, solved, dx[] = { 1,0 }, dy[] = { 0,1 };

// 보드(x, y)에 숫자 num을 넣을 수 있는지 판단
bool check(int x, int y, int num)
{
	bool checkRow = row[x] & (1 << num); // 행 검사(있으면 true)
	bool checkCol = col[y] & (1 << num); // 열 검사(있으면 true)
	bool checkSquare = square[x / 3 * 3 + y / 3] & (1 << num); // 사각형 검사(있으면 true)
	return !checkRow && !checkCol && !checkSquare; // 결과 리턴
}

// 숫자 추가
void addNum(int x, int y, int num)
{
	row[x] |= (1 << num); // 해당 행에 추가
	col[y] |= (1 << num); // 해당 열에 추가
	square[x / 3 * 3 + y / 3] |= (1 << num);  // 해당 사각형에 추가
}

void deleteNum(int x, int y, int num)
{
	row[x] &= (~(1 << num)); // 해당 행에서 삭제
	col[y] &= (~(1 << num)); // 해당 열에서 삭제
	square[x / 3 * 3 + y / 3] &= (~(1 << num)); // 해당 사각형에서 삭제
}

// 0~80 까지 81칸을 모두 방문한다
void solve(int here)
{
	// 모두 방문 했을 경우
	if (here == 81)
	{
		// 결과 출력
		cout << "Puzzle " << t << '\n';
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << '\n';
		}
		solved = 1; // 탈출 플래그 설정
		return;
	}
	// 좌표 계산
	int x = here / 9, y = here % 9;
	// 해당 좌표에 이미 값이 있다면 다음 칸으로 건너뛰기
	if (board[x][y])
	{
		solve(here + 1);
		return;
	}
	// 가능한 모든 타일 순회
	for (int i = 1; i <= 9; i++)
	{
		for (int j = i + 1; j <= 9; j++)
		{
			if (tile[i][j] || tile[j][i]) continue; // 이미 사용한 타일이면 건너뛰기
			// 가로, 세로 타일 추가
			for (int k = 0; k < 2; k++)
			{
				int nx = x + dx[k], ny = y + dy[k]; // 첫 번째는 가로, 두 번째는 세로
				// 범위 및 보드에 숫자가 있는지 검사
				if (nx < 9 && ny < 9 && !board[nx][ny])
				{
					int l = 2; // (i, j), (j, i) 모두 넣어야 한다
					while (l--)
					{
						// 값을 넣을 수 있는지 체크
						bool checkFirst = check(x, y, i);
						bool checkSecond = check(nx, ny, j);
						// 값을 넣을 수 있다면
						if (checkFirst && checkSecond)
						{
							// 타일 사용 체크
							tile[i][j] = 1;
							tile[j][i] = 1;
							// 보드에 값 넣기
							board[x][y] = i;
							board[nx][ny] = j;
							// 숫자 사용 체크
							addNum(x, y, i);
							addNum(nx, ny, j);
							// 다음 지점 탐색
							solve(here + 1);
							// 원상복구
							deleteNum(x, y, i);
							deleteNum(nx, ny, j);
							board[x][y] = 0;
							board[nx][ny] = 0;
							tile[i][j] = 0;
							tile[j][i] = 0;
						}
						// swap
						int tmp = i;
						i = j;
						j = tmp;
					}
				}
			}
			if (solved) return; // 퍼즐을 모두 풀었으면 그냥 리턴
		}
	}
}


int main(void)
{
	while (1)
	{
		int n;
		cin >> n;
		if (!n) break;
		// 초기 세팅
		board.resize(9, vector<int>(9));
		tile.resize(10, vector<int>(10));
		row.resize(9);
		col.resize(9);
		square.resize(9);
		solved = 0;
		// 타일 입력
		for (int i = 0; i < n; i++)
		{
			int first, second;
			string fpos, spos;
			cin >> first >> fpos >> second >> spos;
			// 좌표 계산
			int fx = fpos[0] - 65, fy = fpos[1] - '0' - 1, sx = spos[0] - 65, sy = spos[1] - '0' - 1;
			// 보드에 숫자 추가
			board[fx][fy] = first, board[sx][sy] = second;
			// 숫자 사용 체크
			addNum(fx, fy, first);
			addNum(sx, sy, second);
			// 타일 사용 체크
			tile[first][second] = tile[second][first] = 1;
		}
		for (int i = 1; i <= 9; i++)
		{
			string pos;
			cin >> pos;
			// 좌표 계산
			int x = pos[0] - 65, y = pos[1] - '0' - 1;
			board[x][y] = i; // 숫자 사용 체크
			addNum(x, y, i); // 타일 사용 체크
		}
		solve(0); // 퍼즐 풀기
		t++;
		// 백터 초기화
		board.clear();
		tile.clear();
		row.clear();
		col.clear();
		square.clear();
	}
}