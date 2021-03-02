#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<int> tmp; // 수신 탑 스택
	// 스택 처럼 위부터 탐색
	for (int i = heights.size() - 1; i >= 0; i--)
	{
		int j;
		// i위치 바로 밑부터 탐색
		for (j = i - 1; j >= 0; j--)
		{
			// 가장 먼저 i위치보다 j위치가 더 크다면
			if (heights[i] < heights[j])
			{
				tmp.push_back(j + 1); // push
				break;
			}
		}
		// 탑이 수신 못하면 0 push
		if (j < 0)
			tmp.push_back(j + 1);
	}
	// pop 해서 answer 배열에 push
	for (int i = tmp.size() - 1; i >= 0; i--)
		answer.push_back(tmp[i]);
	return answer;
}
