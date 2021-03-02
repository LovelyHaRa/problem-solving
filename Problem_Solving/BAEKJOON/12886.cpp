#include<iostream>
#include<queue>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

bool check[1001][1001] = { 0, }; // 두 값에 대한 방문 여부

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = a + b + c;
	// 1. 합이 3으로 나누어 떨어지지 않으면 불가능
	if (d % 3) { cout << "0\n"; return 0; }
	// 초기 큐 세팅
	queue <pair<int, int>> q;
	q.push(make_pair(a, b));
	check[a][b] = 1;
	// BFS 탐색
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		int z = d - x - y; // 나머지 하나의 값 구하기
		// 값이 모두 같으면 출력 후 종료
		if (x == y && y == z)
		{
			cout << "1\n";
			return 0;
		}
		// (x,y) (x,z) (y,z) 에 대해서 탐색
		int nx[] = { x,x,y }, ny[] = { y,z,z };
		for (int i = 0; i < 3; i++)
		{
			x = nx[i], y = ny[i];
			// 같으면 건너뛰기
			if (x == y)  continue;
			// x,y 연산
			if (x > y)	x -= y, y *= 2;
			else y -= x, x *= 2;
			// 나머지 하나 구하기
			z = d - x - y;
			// 중복을 피하기 위해 세 값중 최대/최소값을 추출
			int X = min(min(x, y), z), Y = max(max(x, y), z);
			// 큐에 삽입
			if (!check[X][Y])
			{
				check[X][Y] = 1;
				q.push(make_pair(X, Y));
			}
		}
	}
	// 불가능 한 경우
	cout << "0\n";
}
