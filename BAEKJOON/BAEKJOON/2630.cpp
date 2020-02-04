// 분할정복 쿼드트리
#include<iostream>

using namespace std;

int cp[150][150];
int white, blue;
// 분할정복 방법
// 1. 시작지점 저장
// 2. 배열을 모두 순회하면서 시작지점과 달라지는 부분이 있으면
//   2-1. 길이를 반으로 나눈다
//   2-2. 구역을 4개로 나눈다
//   2-3. 각 구역의 왼쪽 위 지점과 길이의 반을 매개변수로 하여 재귀한다.
//   2-4. 재귀가 끝나면 바로 리턴한다
// 3. 2의 조건을 배열 끝까지 만족하지 않는다면
// 4. 하나로 묶을 수 있다는 것을 의미하므로 종이 개수를 증가시킨다.
void quadTree(int x, int y, int length)
{
	int start = cp[x][y]; // 1
	// 2
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (cp[i][j] != start)
			{
				quadTree(x, y, length / 2);
				quadTree(x, y + length / 2, length / 2);
				quadTree(x + length / 2, y, length / 2);
				quadTree(x + length / 2, y + length / 2, length / 2);
				return;
			}
		}
	}
	// 3, 4
	start ? blue++ : white++;
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> cp[i][j];
	}
	// 1. 색종이 개수 초기화.
	white = blue = 0;
	quadTree(0, 0, n);
	cout << white << '\n' << blue << '\n';
}