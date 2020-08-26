#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
	int answer = 0;
	// 1. 오름차순 정렬
	sort(weight.begin(), weight.end());
	// 2. 탐색
	for (int i = 0; i < weight.size(); i++) {
		// 3. 누적합까지는 모두 표현 가능하다
		// 따라서 누적합 다음값이 현재 추보다 작으면
		// 그 수는 표현할 수 없는 최솟값이 된다.
		if (answer + 1 < weight[i]) {
			break;
		}
		// 4. 3이 아닌 경우 무게추 값 누적
		answer += weight[i];
	}
	return answer + 1;
}