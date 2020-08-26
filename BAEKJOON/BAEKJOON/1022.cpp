#include<iostream>
#include<cstdio>
using namespace std;

int s[50][5]; // 소용돌이 저장 (입력 조건에 맞춰 크기 조정)

int main(void){
	
	int r1, c1, r2, c2; // 입력 값
	cin >> r1 >> c1 >> r2 >> c2;
	/* dx dy : x, y 좌표 변화량, 0,1,2,3 : 오른쪽,위쪽,왼쪽,아래쪽 */
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { 1,0,-1,0 };
	/* num : 소용돌이 수, count : 이동횟수, dcount : 현방향 최대 이동 가능 횟수 */
	int num = 1, count = 0, dcount = 1;
	/* x,y : 좌표, d: 좌표 이동 방향 결정 */
	int x, y, d;
	x = y = d = 0;

	/*		
		1. 중단 조건 : 입력 범위 내 꼭짓점 값들이 모두 채워졌을 경우
		2. 출력 범위안에 좌표가 위치해 있을때만 num값을 소용돌이 배열에 저장한다.
		   x-r1, y-c1 이 실제 좌표에 따른 저장 위치
		3. 이동 횟수와 최대 이동가능 횟수가 같을 때 방향을 바꾼다
		4. 방향을 두번 바꿀 때 마다 최대 이동 가능 횟수를 증가시킨다 (소용돌이 수 특징)
		5. 소용돌이수 최대값을 저장하여 자릿수를 구한다
		6. 자릿수에 맞춰 소용돌이 배열을 출력한다
	*/
	while (!((s[0][0] && s[0][c2 - c1]) && (s[r2 - r1][0] && s[r2 - r1][c2 - c1]))) // 1
	{

		if ((x - r1) >= 0 && (x - r1) <= (r2 - r1) && (y - c1) >= 0 && (y - c1) <= (c2 - c1))
			s[x - r1][y - c1] = num; // 2
		num++;
		count++;
		x += dx[d];
		y += dy[d];
		if (count == dcount) // 3
		{
			d = (d + 1) % 4;
			count = 0;
			if (d == 2 || !d) // 4
				dcount++;
		}
	}
	// 5
	int size = 0, k = num;
	while (k)
	{
		k /= 10;
		size++;
	}
	// 6
	for (int i = 0; i <= (r2 - r1); i++)
	{
		for (int j = 0; j <= (c2 - c1); j++)
			printf("%*d ", size, s[i][j]);
		cout << endl;
	}
}