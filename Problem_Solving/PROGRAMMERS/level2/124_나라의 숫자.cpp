#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	// 1. 입력받은 수가 0이 될때까지 반복
	while (n) {
		// 2. 3으로 나눈 나머지를 저장하는데 0은 4로 바꿔서 역순 저장(1,2,4)
		answer = to_string(!(n % 3) ? 4 : n % 3) + answer;
		// 3. 나누어 떨어지는 수는 몫이 1 증가하므로 1을 빼줘야 자릿수가 유지된다
		n = !(n % 3) ? n / 3 - 1 : n / 3;
	}
	return answer;
}