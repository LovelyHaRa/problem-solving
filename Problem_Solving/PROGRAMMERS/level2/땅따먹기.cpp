#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	// dp 이용
	// 점화식 => land[i][j]=(i-1)!=j, max(land[i-1][j=0~3])+land[i][j]
	//            이전 열의 위치를 제외한 값들 중 최대값을 누적
	// 1. 1행에서 최대값 구하기
	for (int i = 0; i < land[0].size(); i++) {
		answer = answer < land[0][i] ? land[0][i] : answer;
	}
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++) {
			// 2. 점화식
			int max = 0;
			for (int k = 0; k < 4; k++) {
				if (j == k) continue;
				max = max < land[i - 1][k] ? land[i - 1][k] : max;
			}
			land[i][j] += max;
			// 3. 최대값 갱신
			answer = answer < land[i][j] ? land[i][j] : answer;
		}
	}
	// 4. 최대값 리턴
	return answer;
}