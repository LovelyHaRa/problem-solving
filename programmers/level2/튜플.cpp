#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 길이를 기준으로 오름차순 비교
bool compare(vector<int>&a, vector<int>&b) {
	return a.size() < b.size() ? true : false;
}

// 두 배열 사이에 공통되지 않는 원소 하나를 리턴하는 함수
int difference(vector<int>&a, vector<int>&b) {
	for (int i = 0; i < a.size(); i++) {
		int j;
		for (j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) break;
		}
		if (j == b.size())
			return a[i];
	}
	return 0;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> tuple;
	vector<int> sub;
	int k = 0;
	// 1. tuple 배열 만들기
	for (int i = 1; i < s.size() - 1; i++) {
		// 여는 중괄호는 무시
		if (s[i] == '{') continue;
		// 닫는 중괄호일 경우
		else if (s[i] == '}') {
			sub.push_back(k); // 집합에 숫자 삽입
			tuple.push_back(sub); // 튜플 배열에 집합 삽입
			sub.clear(); // 집합 초기화
			k = 0; // 숫자 초기화
		}
		// 콤마일 경우
		else if (s[i] == ',') {
			// 이전 문자열이 닫는 중괄호이면 아무것도 안함
			if (s[i - 1] == '}') continue;
			sub.push_back(k); // 집합에 숫자 삽입
			k = 0; // 숫자 초기화
		}
		// 숫자인 경우
		else {
			k *= 10; // 자릿수 유지
			k += s[i] - '0';  // 숫자 누적
		}
	}
	// 2. 집합 길이를 기준으로 정렬
	sort(tuple.begin(), tuple.end(), compare);
	// 3. 초기값 push
	answer.push_back(tuple[0][0]);
	// 4. i, i-1 배열을 비교 하여 공통되지 않는 원소 push 
	for (int i = 1; i < tuple.size(); i++) {
		answer.push_back(difference(tuple[i], tuple[i - 1]));
	}
	// 결과 배열 출력
	return answer;
}

int main(void) {
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}
