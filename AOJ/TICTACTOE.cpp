#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> cache(19683, -2);

// 한 줄 또는 대각선이 o 또는 x로 채워진 경우 true
bool isFinished(const vector<string>& board, char turn)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		// 가로줄
		for (j = 0; j < 3; j++)
			if (board[i][j] == turn) continue;
			else break;
		if (j == 3) return true;
		// 세로줄
		for (j = 0; j < 3; j++)
			if (board[j][i] == turn) continue;
			else break;
		if (j == 3) return true;
	}
	// 왼쪽위 대각선
	for (i = 0; i < 3; i++)
	{
		if (board[i][i] == turn) continue;
		else break;
	}
	if (i == 3) return true;
	// 오른쪽위 대각선
	for (i = 0; i < 3; i++)
	{
		if (board[i][2 - i] == turn) continue;
		else break;
	}
	if (i == 3) return true;
	return false; // 모두 해당안되면 false
}

// 게임판의 상황을 3진수로 변환후 10진수로 저장
int bijection(const vector<string>& board) {
	int ret = 0, k = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int sum = 0;
			if (board[i][j] == 'o') ++sum;
			else if (board[i][j] == 'x') sum += 2;
			sum *= k;
			ret += sum;
			k *= 3;
		}
	}
	return ret;
}

int min(int a, int b) { return a < b ? a : b; }

// turn이 이길 수 있는 경우 1, 비기는 경우 0, 지는 경우 -1
int canWin(vector<string>& board, char turn)
{
	// 기저사례: 다음 턴 상대가 게임을 끝낼 수 있는 경우
	if (isFinished(board, 'o' + 'x' - turn)) return -1;
	// 메모이제이션
	int& ret = cache[bijection(board)];
	if (ret != -2) return ret;
	int minValue = 2;
	// 게임판을 모두 탐색하면서 최솟값 갱신
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '.')
			{
				board[i][j] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[i][j] = '.';
			}
		}
	}
	// 비기거나 갱신이 안된 경우
	if (minValue == 2 || !minValue) return ret = 0;
	// 상대방이 지면 내가 이기고, 상대방이 이기면 내가 진다.
	return ret = -minValue;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		vector<string> board(3);
		int turnCount = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> board[i];
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] != '.')
					turnCount++;
			}
		}
		// 차례 결정
		char turn = (turnCount % 2) ? 'o' : 'x';
		int res = canWin(board, turn);
		if (res == -1)
			turn == 'o' ? cout << "x\n" : cout << "o\n";
		else if (res == 1)
			turn == 'o' ? cout << "o\n" : cout << "x\n";
		else
			cout << "TIE\n";
	}
}
