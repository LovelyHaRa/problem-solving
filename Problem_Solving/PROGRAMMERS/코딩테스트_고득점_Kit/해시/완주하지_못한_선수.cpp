#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	// 해시-맵 이용
	unordered_map<string, int> res;
	// 참가자 카운팅
	for (string p : participant)
		res[p]++;
	// 참가자 중 완주자 제외 (-1 로 구현)
	for (string c : completion)
		res[c]--;
	for (auto r : res)
	{
		// 카운팅 되어있는 상태의 참가자가
		// 완주를 못한 참가자
		if (r.second)
		{
			answer = r.first;
			break;
		}

	}
	return answer;
}
