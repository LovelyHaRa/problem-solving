#include <string>
#include <vector>

using namespace std;

int abs(int a) { return a < 0 ? -a : a; }

string solution(vector<int> numbers, string hand) {
	string answer = "";
	// 키패드를 0부터 시작하는 수로 바뀌서 풀면 쉽다
	int posL = 9, posR = 11; // 초기 위치(*, #)
	for (int i = 0; i < numbers.size(); i++) {
		int k = numbers[i] - 1; // 키패드를 0부터 시작하는 수로 바꾸기
		if (k == -1) k = 10; // 0은 위치 10에 해당한다
		// 왼쪽 버튼에 대한 처리(1, 4 ,7)
		if (k % 3 == 0) {
			answer += 'L';
			posL = k;
		}
		// 오른쪽 버튼에 대한 처리(3, 6, 9)
		else if (k % 3 == 2) {
			answer += 'R';
			posR = k;
		}
		// 가운데 버튼에 대한 처리
		else {
			// 현재 엄지 위치가 사이드에 있는지 확인
			// 사이드에 있다면 가운데로 가야하는 거리 1이 추가되어야 한다
			int distL = (posL % 3 == 0);
			int distR = (posR % 3 == 2);
			// 거리 계산: 키패드의 행의 위치의 차이를 절대값 취한 값
			distL += abs(k / 3 - posL / 3);
			distR += abs(k / 3 - posR / 3);
			// 오른쪽 엄지버튼을 눌러야 하는 경우
			if (distL == distR && hand == "right" || distL > distR) {
				answer += 'R';
				posR = k;
			}
			// 왼쪽 엄지버튼을 눌러야 하는 경우
			else {
				answer += 'L';
				posL = k;
			}
		}
	}
	return answer;
}