#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

map<vector<int>, int> toSort; // 배열의 교환횟수를 저장
// 모든 순열에 대해 toSort[]를 미리 계산
void bfs(int n)
{
	// 순열 생성
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	// bfs를 위한 큐 생성
	queue<vector<int>> q;
	// 시작점 큐에 삽입
	toSort[perm] = 0;
	q.push(perm);
	// bfs 탐색
	while (!q.empty())
	{
		// 큐에서 꺼낸다
		vector<int> here = q.front();
		q.pop();
		// 비용 불러오기
		int cost = toSort[here];
		// 가능한 모든 구간을 뒤집어 본다
		for(int i=0;i<n;i++)
			for (int j = i + 2; j <= n; j++)
			{
				// 뒤집기
				reverse(here.begin() + i, here.begin() + j);
				// 탐색여부 확인
				if (toSort.count(here) == 0)
				{
					toSort[here] = cost + 1;
					q.push(here);
				}
				// 원상 복구
				reverse(here.begin() + i, here.begin() + j);
			}
	}
}

int solve(const vector<int>& perm)
{
	int n = perm.size();
	// perm을 [0~n-1]의 순열로 변환
	vector<int> fixed(n);
	for (int i = 0; i < n; i++)
	{
		int smaller = 0;
		for (int j = 0; j < n; j++)
			if (perm[j] < perm[i])
				smaller++;
		fixed[i] = smaller;
	}
	// 해당 배열의 비용 반환
	return toSort[fixed];
}

int main(void)
{
	// 모든 경우에 대해 미리 계산
	for (int i = 1; i <= 8; i++)
		bfs(i);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> perm(n);
		for (int i = 0; i < n; i++) cin >> perm[i];		
		cout << solve(perm) << '\n';
	}
}