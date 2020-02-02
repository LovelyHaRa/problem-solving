#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	answer = n - lost.size();
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == lost[i])
			{
				answer++;
				reserve[j] = -1;
				lost[i] = -1;
				break;
			}
		}
	}
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (reserve[j] == lost[i] - 1 ||
				reserve[j] == lost[i] + 1)
			{
				answer++;
				reserve[j] = -1;
				break;
			}
		}
	}
	return answer;
}