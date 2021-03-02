#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> k, check;

// DFS를 이용한 조합 구현
void combination(int start, int cnt)
{
	// 기저 사례: 숫자 6개를 체크하면
	if (cnt == 6)
	{
		for (int i = 0; i < n; i++)
		{
			// 체크 된 것만 출력
			if(check[i])
			cout << k[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// start부터 배열 길이까지 반복
	for (int i = start; i < n; i++)
	{
		// 이미 체크되었다면 건너뛰기
		if (check[i]) continue;
		// 체크
		check[i] = 1;
		// DFS 탐색
		combination(i, cnt + 1);
		// 원상복구
		check[i] = 0;
	}
}

int main(void)
{
	while (1)
	{		
		cin >> n;
		if (!n) break;
		k.resize(n);
		check.resize(n);
		for (int i = 0; i < n; i++)
			cin >> k[i];
		sort(k.begin(), k.end());
		combination(0, 0);
		cout << '\n';
		k.clear();
		check.clear();
	}
}