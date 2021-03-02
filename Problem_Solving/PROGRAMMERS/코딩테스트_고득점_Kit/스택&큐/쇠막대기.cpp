#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	// 1. 여는 괄호는 스택포인터 증가
	// 2. 닫는 괄호를 만났을 때
	// 3. 스택포인터 감소
	// 4. 직전 값이 여는 괄호일 때: 쇠막대기에 스택 포인터 만큼 추가
	// 5. 4가 아니면 쇠막대기에 1 추가
	int top = 0;
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(')
			top++;
		else if (arrangement[i] == ')') {
			top--;
			if (i > 0 && arrangement[i - 1] == '(') {
				answer += top;
			}
			else {
				answer += 1;
			}
		}
	}
	return answer;
}
