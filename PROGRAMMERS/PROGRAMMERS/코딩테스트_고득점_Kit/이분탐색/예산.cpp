#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 백준 2512 풀이 참조
int solution(vector<int> budgets, int M) {
	int answer = 0;
	int low = 0, high = 0;
	for (int i = 0; i < budgets.size(); i++)
		high = max(high, budgets[i]);
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int sum = 0;
		for (int i = 0; i < budgets.size(); i++)
			sum += min(budgets[i], mid);
		if (sum <= M)
		{
			answer = max(mid, answer);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return answer;
}