#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	// 1. lost, reserve에 둘다 포함된 사람 제외
	answer = n - lost.size(); // 초기값: 전체-없는사람
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == lost[i])
			{
				answer++;
				//  -1로 설정해서 제외시킴
				reserve[j] = -1;
				lost[i] = -1;
				break;
			}
		}
	}
	// 2. 없는사람 처음부터 순차적으로 조건탐색
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			// 조건 일치하면 
			if (reserve[j] == lost[i] - 1 ||
				reserve[j] == lost[i] + 1)
			{
				answer++;
				// 받는사람 제외시킴
				reserve[j] = -1;
				break;
			}
		}
	}
	return answer;
}