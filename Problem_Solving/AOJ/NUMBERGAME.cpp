#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> board;
vector<vector<int>> cache;
const int EMPTY = -987654321;

int max(int a, int b) { return a > b ? a : b; }

int play(int left, int right)
{
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != EMPTY) return ret;
	// 왼쪽 수를 가져가는 경우와 오른쪽 수를 가져가는 경우 중 큰 값을 저장
	ret = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	// 수를 제거하는 경우
	if (right - left >= 2)
	{
		// (서하 점수) - (현우 점수)를 구하기 위해 부호 반전
		ret = max(ret, -play(left + 2, right)); // 왼쪽 수 2개 제거
		ret = max(ret, -play(left, right - 2)); // 오른 쪽 수 2개 제거
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		board.resize(n);
		for (int i = 0; i < n; i++)
			cin >> board[i];
		cache.resize(n, vector<int>(n, EMPTY));
		cout << play(0, n - 1) << '\n';
		board.clear();
		cache.clear();
	}
}
