#include<iostream>

using namespace std;

const int MAP_SIZE = 20;

int main(void)
{
	int n, m, x, y, k;
	int dice[7] = { 0 }; // 주사위 배열, 윗면은 1 아랫면은 6
	int map[MAP_SIZE][MAP_SIZE] = { 0 }; // 지도
	int dx[4] = { 0,0,-1,1 }; // 명령에 따른 x좌표 이동 크기
	int dy[4] = { 1,-1,0,0 }; // 명령에 따른 y좌표 이동 크기
	// 입력
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	// 명령 처리
	for (int i = 0; i < k; i++)
	{
		int order;
		cin >> order;
		// 이동 좌표 계산
		int xx, yy;
		xx = x + dx[order - 1];
		yy = y + dy[order - 1];
		// 좌표가 범위안에 있는지 판단
		if (!(xx >= 0 && xx < n&&yy >= 0 && yy < m))
			continue;
		//이동 좌표 갱신
		x = xx;
		y = yy;
		// 명령에 따른 주사위 인덱스 교체
		switch (order)
		{
		case 1:
			swap(dice[1], dice[4]);
			swap(dice[3], dice[4]);
			swap(dice[4], dice[6]);
			break;
		case 2:
			swap(dice[1], dice[3]);
			swap(dice[3], dice[6]);
			swap(dice[6], dice[4]);
			break;
		case 3:
			swap(dice[1], dice[2]);
			swap(dice[2], dice[6]);
			swap(dice[6], dice[5]);
			break;
		case 4:
			swap(dice[1], dice[5]);
			swap(dice[5], dice[6]);
			swap(dice[6], dice[2]);
		}		
		// 조건에 맞게 데이터 저장
		if (map[x][y] == 0)
			map[x][y] = dice[6];
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		// 윗면 출력
		cout << dice[1] << endl;
	}
}