#include<iostream>
#include<vector>
#include<set>

using namespace std;

int order(const vector<int>& russian, const vector<int>& korean)
{
	int n = korean.size(), wins = 0;
	multiset<int> ratings(korean.begin(), korean.end()); // 이진 탐색 트리에 저장
	for (int rus = 0; rus < n; rus++)
	{
		// 어떤 선수도 이길 수 없는 경우
		if (*ratings.rbegin() < russian[rus])
			ratings.erase(ratings.begin()); // 가장 낮은 레이팅 선수 출전
		else
		{
			// 이길 수 있는 선수 중 최소값의 레이팅을 가진 선수를 출전
			ratings.erase(ratings.lower_bound(russian[rus]));
			wins++; // 승수 추가
		}
	}
	return wins;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> russian(n), korean(n);
		for (int i = 0; i < n; i++)
			cin >> russian[i];
		for (int i = 0; i < n; i++)
			cin >> korean[i];
		cout << order(russian, korean) << '\n';
	}
}