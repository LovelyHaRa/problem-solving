#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		multiset<int> pq; // 중복 가능한 set
		while (k--)
		{
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') pq.insert(n); // 삽입(자동 정렬)
			else
			{
				if (pq.empty()) continue;
				pq.erase((n < 0 ? pq.begin() : --pq.end())); // 삭제
			}
		}
		if (pq.empty()) cout << "EMPTY\n";
		else cout << *--pq.end() << ' ' << *pq.begin() << '\n'; // 최댓값, 최솟값 출력
	}
}