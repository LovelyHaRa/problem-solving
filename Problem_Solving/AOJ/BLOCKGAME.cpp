#include<iostream>
#include<vector>

using namespace std;

// 좌표에 해당하는 비트 계산
inline int cell(int y, int x) { return 1 << (y * 5 + x); }

vector<int> moves;
// 게임판 위에 덮을 수 있는 블록의 모든 경우의 수를 구함
void precalc()
{
	// L 모양 블록의 경우를 먼저구함(그래야 빨리끝남)
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			// 1. 사각형 모양 저장
			vector<int> cells;
			for (int dy = 0; dy < 2; dy++)
			{
				for (int dx = 0; dx < 2; dx++)
					cells.push_back(cell(y + dy, x + dx));
			}
			int square = cells[0] + cells[1] + cells[2] + cells[3];
			// 2. 사각형 모양에서 하나씩 빼면서 경우를 저장
			for (int i = 0; i < 4; i++)
				moves.push_back(square - cells[i]);
		}
	}
	// 1자 모양 블록의 경우
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}

vector<char> cache(1 << 25 + 1, -1); // 메모리 초과때문에 char형으로 저장

char play(int board)
{
	char& ret = cache[board];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < moves.size(); i++)
	{
		// 겹치지 않는 경우
		if ((moves[i] & board)==0)
		{
			// 해당 블록을 배치시킨 후 재귀 탐색
			if (!play(board | moves[i]))
			{
				ret = 1;
				break;
			}
		}
	}
	return ret;
}

int main(void)
{
	precalc();
	int c;
	cin >> c;
	while (c--)
	{
		int board = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				char k;
				cin >> k;
				if (k == '#') board += cell(i, j);
			}
		}
		int res = play(board);
		res ? cout << "WINNING\n" : cout << "LOSING\n";
	}
}
