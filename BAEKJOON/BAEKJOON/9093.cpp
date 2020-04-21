#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	cin.ignore(); // 버퍼 지우기
	while (t--)
	{
		string s;
		getline(cin,s); // 한줄 입력받음
		string u;
		// 문자열 탐색
		for (int i = 0; i < s.size(); i++)
		{
			// 공백이면 단어 역순 출력
			if (s[i] == ' ')
			{
				reverse(u.begin(), u.end());
				cout << u << ' ';
				u = ""; // 새로운 단어를 저장하기 위해 초기화
			}
			// 그렇지 않으면 단어 저장
			else
				u.push_back(s[i]);
			
		}
		// 마지막 단어 역순 출력
		reverse(u.begin(), u.end());
		cout << u;
		cout << '\n';
	}
}