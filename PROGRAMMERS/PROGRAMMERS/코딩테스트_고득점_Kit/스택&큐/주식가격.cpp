#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	// 다음 시간대부터 탐색하다가
	// 떨어지는 순간이 올 때 구간을 count에 저장
	// 마지막은 항상 0이므로 0 추가
	for (int i = 0; i < prices.size() - 1; i++)
	{
		int count = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j] || j == prices.size() - 1) {
				count = j - i;
				break;
			}
		}
		answer.push_back(count);
	}
	answer.push_back(0);
	return answer;
}