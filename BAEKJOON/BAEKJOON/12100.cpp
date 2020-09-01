#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int n; // 보드 크기
int maxBlockSize = 0; // 최대 블록 크기

int max(int a, int b) { return a > b ? a : b; }

// 블록을 상하좌우 이동 시킨 결과를 반환
vector<vector<int>> moveBlock(vector<vector<int>> curBoard, int dir)
{
	// dir: 상, 좌, 우, 하
	queue<int> q; // 블록을 저장시킬 큐
	// 1. 블록을 큐에 저장
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (dir)
			{
			case 0:
				if (curBoard[j][i])
					q.push(curBoard[j][i]);
				curBoard[j][i] = 0;
				break;
			case 1:
				if (curBoard[i][j])
					q.push(curBoard[i][j]);
				curBoard[i][j] = 0;
				break;
			case 2:
				if (curBoard[i][n - j - 1])
					q.push(curBoard[i][n - j - 1]);
				curBoard[i][n - j - 1] = 0;
				break;
			case 3:
				if (curBoard[n - j - 1][i])
					q.push(curBoard[n - j - 1][i]);
				curBoard[n - j - 1][i] = 0;
				break;
			}
		}
		// 2. 큐에서 블록을 빼서 합치기
		int curBlock = 0, idx = 0;
		while (!q.empty())
		{
			curBlock = q.front();
			q.pop();
			switch (dir)
			{
			case 0:
				// 현재 위치에 블록이 저장되지 않은 경우
				if (!curBoard[idx][i]) curBoard[idx][i] = curBlock;
				// 현재 위치에 블록이 저장되어 있고 꺼낸 블록과 값이 같은 경우
				else if (curBoard[idx][i] == curBlock) curBoard[idx++][i] *= 2;
				// 위 두가지 경우가 아닌 경우
				else curBoard[++idx][i] = curBlock;
				break;
			case 1:
				if (!curBoard[i][idx]) curBoard[i][idx] = curBlock;
				else if (curBoard[i][idx] == curBlock) curBoard[i][idx++] *= 2;
				else curBoard[i][++idx] = curBlock;
				break;
			case 2:
				if (!curBoard[i][n - idx - 1]) curBoard[i][n - idx - 1] = curBlock;
				else if (curBoard[i][n - idx - 1] == curBlock) curBoard[i][n - (idx++) - 1] *= 2;
				else curBoard[i][n - (++idx) - 1] = curBlock;
				break;
			case 3:
				if (!curBoard[n - idx - 1][i]) curBoard[n - idx - 1][i] = curBlock;
				else if (curBoard[n - idx - 1][i] == curBlock) curBoard[n - (idx++) - 1][i] *= 2;
				else curBoard[n - (++idx) - 1][i] = curBlock;
				break;
			}
		}
	}
	return curBoard;
}

// 보드에서 최대 블록 사이즈를 찾는다
int findMaxBlockSize(vector<vector<int>> board)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, board[i][j]);
	return ret;
}

// dfs 탐색으로 모든 경우 조사
void move(vector<vector<int>> curBoard, int cnt, int curMaxBlockSize)
{
	// 5번 이동 했으면
	if (cnt == 5)
	{
		maxBlockSize = max(maxBlockSize, curMaxBlockSize); // 최대 블록 사이즈 구하기
		return;
	}
	// 상하좌우 이동
	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> nextBoard = moveBlock(curBoard, i); // 블록 이동 결과 구하기
		move(nextBoard, cnt + 1, findMaxBlockSize(nextBoard)); // dfs 탐색
	}
}

int main(void)
{
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	move(board, 0, findMaxBlockSize(board));
	cout << maxBlockSize << '\n';
}