#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
	int answer = 0;
	// 1. 친구들 배열을 만든다.
	vector<char> photo = { 'A','C','F','J','M','N','R','T' };
	// 2. 순열 완전탐색 (8! 이라서 가능)
	do {
		int i;
		// 3 조건 개수만큼 반복
		for (i = 0; i < n; i++) {
			// 4. 데이터 추출
			char a = data[i][0], b = data[i][2]; // 친구 a, b
			char c = data[i][3]; // 비교 조건
			int interval = data[i][4] - '0'; // a, b 사이의 친구 수
			// 5. 친구 위치 찾기
			int idx_a = -1, idx_b = -1; // a, b 인덱스
			for (int j = 0; j < 8; j++) {
				if (a == photo[j])
					idx_a = j;
				else if (b == photo[j])
					idx_b = j;
			}
			// 6. a-b의 절대값 구하기
			int max = idx_a > idx_b ? idx_a : idx_b;
			int min = idx_a < idx_b ? idx_a : idx_b;
			int ab = max - min - 1;
			// 7. 비교조건을 만족 안하면 break
			if (c == '=' && ab != interval) break; // 같아야하는데 같지 않으면 break
			else if (c == '>' && ab <= interval) break; // 초과해야하는데 이하이면 break
			else if (c == '<' && ab >= interval) break; // 미만이어야하는데 이상이면 break
		}
		// 8. 모든 조건을 만족하면 정답 수 증가
		if (i == n) answer++;
	} while (next_permutation(photo.begin(), photo.end())); // 모든 순열 생성
	return answer;
}