// 큐 문제
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	int n;
	cin >> n;
	// 1. 1부터 n 까지 큐에 삽입
	// 2. 큐에서 꺼냄
	// 3. 큐가 비어있으면 마지막 값 출력
	// 4. 아니면 큐에서 꺼냄
	// 5. 4에서 꺼낸 수 다시 큐에 삽입.
	// 6. 2~5 반복, 3의 조건에서 탈출
	// 1
	int k = 1;
	while (k <= n)
		q.push(k++);
	int res;
	// 6
	while (1)
	{
		// 2
		res = q.front();
		q.pop();
		// 3
		if (q.empty())
			break;
		// 4
		int t = q.front();
		q.pop();
		// 5
		q.push(t);
	}
	cout << res << '\n';
}
