#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(void)
{
	list<char> s;
	string t;
	cin >> t;
	// 1. 문자열 리스트에 저장
	for (int i = 0; i < t.size(); i++)
		s.push_back(t[i]);
	// 2. 초기 포인터 세팅
	list<char>::iterator start, end, cursor, del; // 시작점, 종료점, 현재위치, 삭제타겟
	start = s.begin(); // 초기 시작점 세팅
	end = s.end(); // 초기 종료점 세팅
	cursor = s.end(); // 처음 커서의 위치는 종료점
	// 3. 명령 처리
	int n;
	cin >> n;
	while (n--)
	{
		// 4. 명령 구분
		char c;
		cin >> c;
		// 왼쪽 이동, 커서가 시작점이면 무시
		if (c == 'L' && cursor != start)
			cursor--;
		// 오른쪽 이동, 커서가 종료점이면 무시
		else if (c == 'D' && cursor != end)
			cursor++;
		// 삭제, 커서가 시작점이면 무시
		else if (c == 'B' && cursor != start)
		{
			del = --cursor; // 삭제지점 저장
			cursor = s.erase(del); // 리턴값은 삭제 후 바로 오른쪽 이터럴
		}
		// 삽입
		else if (c == 'P')
		{
			// 삽입할 문자 입력받음
			char x;
			cin >> x;
			// 커서 위치에 따른 처리
			if (start == cursor)
				s.push_front(x);
			else if (end == cursor)
				s.push_back(x);
			else
				s.insert(cursor, x); // 현재 이터럴 왼쪽에 추가됨			
		}
		// 삭제, 삽입은 리스트가 갱신되므로 시작, 끝지점도 갱신
		start = s.begin();
		end = s.end();
	}
	// 리스트 출력
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it;
}