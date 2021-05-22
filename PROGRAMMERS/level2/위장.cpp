#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> F;
	// 1. 의상의 종류를 key로 하여 카운팅
	for (int i = 0; i < clothes.size(); i++)
		F[clothes[i][1]]++;
	// 2. map 탐색
	for (auto i : F)
		// 3. 종류의수+1을 곱해셔 누적(선택을 안할 수도 있으므로 +1)
		answer *= (i.second + 1);
	// 4. 모두 다 선택 안하는 조건을 빼서 리턴
	return answer - 1;
}
