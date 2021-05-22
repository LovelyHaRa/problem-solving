#include<iostream>

using namespace std;

int n, r, c, res;

void Z(int x, int y, int size)
{
	// 위치에 도달하면
	if (x == r && y == c)
	{
		cout << res << '\n';
		return;
	}
	// 범위안에 속하면
	if (r >= x && r < x + size && c >= y && c < y + size)
	{
		// Z모양 재귀 탐색
		Z(x, y, size / 2); // 좌상단
		Z(x, y + size / 2, size / 2); // 우상단
		Z(x + size / 2, y, size / 2); // 좌하단
		Z(x + size / 2, y + size / 2, size / 2); // 우하단
	}
	else res += size * size; // 그렇지 않으면 해당 사분면 건너뛰기
}

int main(void)
{
	cin >> n >> r >> c;
	Z(0, 0, 1 << n);
}
