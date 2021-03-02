#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	vector<char> s(number.size());
	int i = 0, top = 0, t = 0;
	// 1. 첫번째 수를 스택에 넣기
	s[top] = number[i++];
	// 2. 숫자 끝까지 탐색하는데 제거가 완료되면 탈출
	while (i != number.size() && t != k) {
		// 3. 스택이 빌 때까지 현재 숫자보다 작은 수 제거
		while (top >= 0 && s[top] < number[i]) {
			top--;
			t++;
			// 3-1. 제거할 개수를 초과하면 탈출
			if (t == k)
				break;
		}
		// 4. 스택이 꽉 차있으면 스택에 현재 숫자를 넣지 않는다.
		if (top == number.size() - k - 1)
			i++;
		// 5. 그렇지 않으면 스택에 현재 숫자를 넣음
		else
			s[++top] = number[i++];
	}
	// 6. 제거가 완료 되어 미리 탈출 했을 때, 나머지 숫자를 집어넣는다.
	if (i < number.size()) {
		for (int j = i; j < number.size(); j++) {
			s[++top] = number[j];
		}
	}
	// 7. 문자열로 만든다.
	for (int j = 0; j <= top; j++) {
		answer += s[j];
	}
	return answer;
}