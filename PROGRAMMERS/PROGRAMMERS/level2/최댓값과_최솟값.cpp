#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	// stringstream 사용
	stringstream st;
	st.str(s); // 문자열 복사
	int min = 1987654321, max = -1987654321, k;
	// 공백은 무시하고 st의 값이 k의 자료형(int)이 아닐 때 까지 반복
	while (st >> k) {
		// k는 st의 부분 문자열이 형변환 된 상태
		// 최솟값, 최대값을 판별
		min = min > k ? k : min;
		max = max < k ? k : max;
	}
	answer += to_string(min) + ' ' + to_string(max);
	return answer;
}