#include <string>
#include <vector>
#include <stack>

using namespace std;

// 스택 이용
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	stack<int> s;
	// 1. 작업 배열 인덱스 스택에 쌓기
	// 2. 스택이 빌때까지 아래 내용 반복
	// 3. 작업진행
	// 4. 스택값을 인덱스로 해서 100미만의 값이 나올때 까지 카운트 및 pop
	// 5. 한번이라도 pop 했으면 answer에 추가
	
	// 1
	int n = progresses.size() - 1;
	while (n >= 0)
		s.push(n--);
	// 2
	while (!s.empty()) {
		// 3
		for (int i = 0; i < progresses.size(); i++)
			progresses[i] += speeds[i];
		// 4
		int count = 0;
		while (progresses[s.top()] >= 100)
		{
			s.pop();
			count++;
			if (s.empty())
				break;
		}
		// 5
		if (count > 0)
			answer.push_back(count);
	}
	return answer;
}
