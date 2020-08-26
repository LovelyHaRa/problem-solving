#include<iostream>
#include<cstring>

using namespace std;

int n; // 학생 수
bool areFriends[10][10]; // 친구 쌍 표현

// 문제 해결을 위한 재귀 호출 코드
int countPairings(bool[10]);

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int C; // 테스트케이스
	int m; // 친구 쌍의 수
	cin.sync_with_stdio(false);
	cin >> C;
	while (C > 0)
	{
		// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
		bool taken[10] = { false };
		memset(areFriends, false, sizeof(areFriends));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			areFriends[x][y] = areFriends[y][x] = true;
		}
		cout << countPairings(taken) << endl;
		C--;
	}
}

int countPairings(bool taken[10])
{
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	// 기저 사례 : 모든 학생이 짝을 찾으면 한가지 방법을 찾았으니 종료한다.
	if (firstFree == -1) return 1;
	int ret = 0;
	// 이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}