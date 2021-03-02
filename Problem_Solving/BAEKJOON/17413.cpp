#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s); // 입력 받음
	string t; // 태그, 단어를 저장
	int tag = 0; // 인덱스가 태그 사이에 위치하고 있는지 여부
	for (int i = 0; i < s.size(); i++)
	{
		// 1. 역순 문자를 출력해야할 조건: 공백문자 이고 태그사이에 없거나 태그 시작점인 경우
		if ((s[i] == ' ' && !tag) || (s[i] == '<'))
		{
			// 역순 문자 출력
			reverse(t.begin(), t.end());
			cout << t;
			// t 초기화
			t = "";
			// 태그 시작점인 경우 '<' 저장
			if (s[i] == '<')
			{
				t += '<';
				tag = 1; // 태그 시작
			}
			// 공백이었을 경우 공백 추가 출력
			else
				cout << ' ';
		}
		// 2. 태그를 출력해야할 조건(단순 문자 출력): 태그 종료점인경우
		else if (s[i] == '>')
		{
			// '>' 저장
			t += '>';
			// 문자열 출력
			cout << t;
			// t 초기화
			t = "";
			tag = 0; // 태그 종료
		}
		// 3. 1, 2가 아닌 경우에는 단어 저장
		else
			t += s[i];
	}
	// 마지막 문자가 태그가 아니었다면 마지막 단어 리버스 출력
	if (s[s.size() - 1] != '>')
	{
		reverse(t.begin(), t.end());
		cout << t;
	}
}
