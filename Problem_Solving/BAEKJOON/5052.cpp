// 문자열 해시
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<string> phone;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			phone.push_back(s);
		}
		// 1. 정렬
		// 2. 입력 전화번호 개수 -1 만큼 탐색
		// 3. 현재 전화번호 길이가 다음 전화번호 길이 보다 작을 때
		// 4. find를 이용해 문자열을 검색, 시작 인덱스가 0이면 break
		// 5. 끝까지 탐색하면 YES 아니면 NO

		sort(phone.begin(), phone.end()); // 1

		int res = 1;
		// 2
		for (int i = 0; i < phone.size() - 1; i++)
		{
			// 3
			if (phone[i].length() < phone[i + 1].length())
			{
				// 4
				if (!phone[i + 1].find(phone[i]))
				{
					res = 0;
					break;
				}
			}
		}
		cout << (res ? "YES\n" : "NO\n"); // 5
	}
}
