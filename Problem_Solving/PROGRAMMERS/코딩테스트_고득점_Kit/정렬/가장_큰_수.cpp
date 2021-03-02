#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 4 : 비교함수
// 정순, 역순으로 합친 결과를 내림차순으로 비교
bool compare(const string a, const string b)
{
	string ab = a + b; // 정순
	string ba = b + a; // 역순
	return ab > ba ? true : false; // 내림차순 비교
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	// 1. 0 인지 검사
	// 2. 숫자를 문자로 치환하여 배열에 삽입
	// 3. 주어진 수가 모두 0이면 0 하나만 반환
	// 4. 두 문자열을 정순, 역순으로 합쳐서 사전순 비교 내림차순 정렬
	// 5. 정렬 결과를 하나의 문자열로 만들기
	int zero = 0;
	for (int i : numbers)
	{
		// 1
		if (!i)
			zero++;
		str.push_back(to_string(i)); // 2
	}
	// 3
	if (numbers.size() == zero)
		return "0";
	// 4
	sort(str.begin(), str.end(), compare);
	// 5
	for (auto i : str)
		answer += i;
	return answer;
}