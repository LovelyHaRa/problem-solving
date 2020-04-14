#include <vector>

using namespace std;

int p, q; // m, n 전역으로 사용

int area(int location, int x, int y, vector<vector<int>>& picture) {
	int sum = 1; // 영역 넓이, 1씩 누적시킴
	// 좌표가 영역을 넘어가는 경우, 색이 일치하지 않는 경우 0을 리턴
	if (x < 0 || y < 0 || x >= p || y >= q || picture[x][y] != location)
		return 0;
	else {
		// 체크의 의미로 0을 대입
		picture[x][y] = 0;
		// 4방향 재귀탐색
		sum += area(location, x, y + 1, picture);
		sum += area(location, x, y - 1, picture);
		sum += area(location, x + 1, y, picture);
		sum += area(location, x - 1, y, picture);
		// 누적 영역합 반환
		return sum;
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	p = m;
	q = n;
	// 1. 브루트 포스 탐색
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// 2. 체크되지 않았거나 색이 없는 경우 건너뜀
			if (!picture[i][j]) continue;
			// 3. 영역의 합을 구하기 위해 재귀탐색
			int sum = area(picture[i][j], i, j, picture);
			number_of_area++; // 영역수 증가
			// 최댓값 갱신
			max_size_of_one_area = max_size_of_one_area < sum ? sum : max_size_of_one_area;
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}