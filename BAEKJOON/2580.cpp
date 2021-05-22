// 백트래킹 문제
// DFS 이용

#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>

using namespace std;

int sudoku[9][9] = { 0 };
vector<pair<int, int>> blank; // 비어있는 칸 좌표 저장

// 가로 숫자 검사
bool check_horizontal(int r, int num)
{
	for (int c = 0; c < 9; c++)
	{
		if (sudoku[r][c] == num)
			return false;
	}
	return true;
}

// 세로 숫자 검사
bool check_vertical(int c, int num)
{
	for (int r = 0; r < 9; r++)
	{
		if (sudoku[r][c] == num)
			return false;
	}
	return true;
}

// 사각형 숫자 검사
bool check_square(int r, int c, int num)
{
	// 해당 좌표가 속하는 사각형 영역 시작점 구하기
	int x = (r / 3) * 3;
	int y = (c / 3) * 3;
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
			if (sudoku[i][j] == num)
				return false;
	}
	return true;
}

void dfs(int idx)
{
	// 칸이 모두 채워지면 출력
	if (idx == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << sudoku[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

	// 1부터 9까지 차례대로 넣어보면서 가능여부 체크
	for (int i = 1; i <= 9; i++)
	{
		int r = blank[idx].first;
		int c = blank[idx].second;
		if (check_horizontal(r, i) && check_vertical(c, i) && check_square(r, c, i))
		{
			sudoku[r][c] = i;
			dfs(idx + 1);
			sudoku[r][c] = 0; // 백트래킹
		}
	}
}

int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			// 비어있는 칸은 따로 관리
			if (!sudoku[i][j])
				blank.push_back({ i,j });
		}
	}
	dfs(0);
}
