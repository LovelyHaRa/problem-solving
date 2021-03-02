#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	// 1. 정렬
	// 2. 입력 전화번호 개수 -1 만큼 탐색
	// 3. 현재 전화번호 길이가 다음 전화번호 길이 보다 작을 때
	// 4. find를 이용해 문자열을 검색, 시작 인덱스가 0이면 break
	// 5. 끝까지 탐색하면 YES 아니면 NO

	// 1
	sort(phone_book.begin(), phone_book.end());
	// 2
	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		// 3
		if (phone_book[i].length() < phone_book[i + 1].length())
		{
			// 4
			if (!phone_book[i + 1].find(phone_book[i]))
			{
				answer = false;
				break;
			}
		}
	}
	// 5
	return answer;
}