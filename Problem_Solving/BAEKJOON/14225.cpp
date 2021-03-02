#include<iostream>
#include<vector>

using namespace std;

vector<bool> num(2000001); // 부분 합 체크
vector<int> s(20); // 수열
int n;

// 수열의 원소 위치, 지금까지 계산된 부분 합을 가지고 dfs 탐색
void makeSum(int here, int psum)
{
	num[psum] = 1; // 부분 합 체크
	// 수열의 범위를 벗어나면 리턴
	if (here >= n) return;
	makeSum(here + 1, psum + s[here]); // 현재 원소를 부분 합에 포함
	makeSum(here + 1, psum); // 현재 원소를 부분 합에 포함하지 않음
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	makeSum(0, 0);
	int i = 0;
	while (1)
		// 최초로 발견되는 false 값이 부분 합으로 만들 수 없는 숫자
		if (!num[++i])
		{
			cout << i << '\n';
			return 0;
		}
}
