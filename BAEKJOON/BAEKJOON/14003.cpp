#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache, a, choices;

int lis(int start)
{
	// 메모이제이션
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	// 길이는 무조건 1부터 시작(자기자신)
	ret = 1;
	int bestNext = -1;
	for (int next = start+1; next < n; next++)
	{
		if (start == -1 || a[start] < a[next])
		{
			// 다음 원소의 수열 길이 구하기
			int c = lis(next) + 1;
			// 길이 최대값 갱신
			if (ret < c)
			{
				ret = c;
				bestNext = next;
			}
		}
	}
	// 최대값 인덱스 저장
	choices[start + 1] = bestNext;
	return ret;
}

// choices를 기반으로 LIS 수열을 만든다.
void reconstruct(int start, vector<int>& seq)
{
	// choices[i] = 다음 최대 길이 수열 값 위치
	if (start != -1) seq.push_back(a[start]); // 있으면 LIS 수열에 저장
	int next = choices[start + 1]; // 다음 위치 구하기
	if (next != -1) reconstruct(next, seq); // 재귀 탐색
}

int main(void)
{
	cin >> n;
	a.resize(n);
	cache.resize(n + 1, -1);
	choices.resize(n + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	lis(-1); // 모든 시작지점 탐색
	vector<int> seq;
	reconstruct(choices[0], seq);
	int cnt = seq.size();
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << seq[i] << ' ';
}