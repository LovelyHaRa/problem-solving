// 브루트포스, 수학
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	// 전체 격자 개수
	int width = brown + red;
	// 경우의 수 : 전체 격자 개수의 약수
	for (int i = width / 2; i >= 1; i--) {
		// 약수 발견 시
		if (!(width%i)) {
			// x: 가로 길이, y: 세로 길이
			int x = i;
			int y = width / i;
			// 카펫은 세로가 가로보다 길 수 없음
			if (x < y) continue;
			// 빨간색 격자 개수: (가로길이-2)*(세로길이-2)
			int red_cnt = (x - 2)*(y - 2);
			// 갈색 격자 개수: (전체 격자개수)-(빨간색 격자 개수)
			int brown_cnt = width - red_cnt;
			// 입력과 일치여부 검사: 일치하면 가로, 세로길이 저장
			if (red_cnt == red && brown_cnt == brown) {
				answer.push_back(x);
				answer.push_back(y);
				break;
			}
		}
	}
	return answer;
}
