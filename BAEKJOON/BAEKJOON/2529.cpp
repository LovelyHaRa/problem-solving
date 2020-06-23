#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n;
vector<char> inequal;
vector<int> check(10);
string biggest, smallest;

// 조건에 따라 DFS 탐색을 실시한다
void process(int cnt, string selected)
{
	// 기저 사례: cnt==n+1
	if (cnt == n + 1)
	{
		// 최댓값 갱신
		if (biggest.compare(selected) < 0)
			biggest = selected;
		// 최솟값 갱신
		if (smallest.compare(selected) > 0)
			smallest = selected;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue; // 조건 1: 숫자는 모두 달라야 한다.
		// 조건 2: 입력 받은 부등호들을 만족한다
		if (cnt > 0)
		{
			switch (inequal[cnt - 1])
			{
			case '>':
				if (selected[cnt - 1] <= (i + '0')) continue;
				break;
			case '<':
				if (selected[cnt - 1] >= (i + '0')) continue;
				break;
			}
		}
		// 체크
		check[i] = 1;
		// 다음 값 탐색
		process(cnt + 1, selected + to_string(i));
		// 원상복구
		check[i] = 0;
	}
}

int main(void)
{
	cin >> n;
	inequal.resize(n);
	for (int i = 0; i <= n; i++)
	{
		if (i != n) cin >> inequal[i];
		// 초기값 저장
		biggest += to_string(i); // n=2이면 012
		smallest += to_string(9 - i); // n=2이면 987
	}
	process(0, "");
	cout << biggest << '\n' << smallest << '\n';
}