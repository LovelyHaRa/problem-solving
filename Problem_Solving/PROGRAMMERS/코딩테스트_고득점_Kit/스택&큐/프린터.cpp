#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	priority_queue<int> pq; // 우선순위 큐
	queue<pair<int, int>> q; // 인덱스와 순위값을 같이 큐에 넣음
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push({ i,priorities[i] });
	}
	// 우선순위 큐는 값을 넣으면 무조건 내림차순 정렬되어 유지
	// 1. 큐에서 값을 꺼낸다.
	// 2. 우선순위 큐와 순위값을 비교한다
	// 3. 같으면 우선순위 큐에서 값 꺼내고 answer 증가
	// 4. 인덱스가 목표위치이면 break
	// 5. 2가 false이면 다시 큐에 집어넣음
	while (!q.empty())
	{
		// 1
		int index = q.front().first;
		int pri = q.front().second;
		q.pop();
		// 2
		if (pri == pq.top())
		{
			// 3
			pq.pop(); 
			answer++;
			// 4
			if (index == location)
				break;
		}
		// 5
		else
			q.push({ index,pri });
	}
	return answer;
}

int main(void)
{	
	solution({ 2,1,3,2 }, 2);
}