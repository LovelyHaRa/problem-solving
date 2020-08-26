#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int c = 0;
	while (c < commands.size())
	{
		int i, j, k;
		i = commands[c][0];
		j = commands[c][1];
		k = commands[c][2];
		vector<int> tmp;
		// 1. 배열 쪼개기
		for (int x = i - 1; x < j; x++)
			tmp.push_back(array[x]);
		// 2. 정렬 함수를 이용한 정렬
		sort(tmp.begin(), tmp.end());
		// 3. 해당 위치 원소 푸시
		answer.push_back(tmp[k - 1]);
		c++;
	}

	return answer;
}