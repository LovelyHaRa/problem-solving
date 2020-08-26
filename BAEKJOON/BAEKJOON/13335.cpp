// 시뮬레이션 문제
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int n, w, L;
	cin >> n >> w >> L;
	vector<int> truck(n);
	for (int i = 0; i < n; i++)
		cin >> truck[i];
	queue<int> q;
	int res, sum;
	res = sum = 0;
	// 1. 큐가 비었을 때 : 큐에 트럭 추가, 무게 누적, 시간 추가
	// 2. 큐가 꽉찼을 때 : 큐에서 트럭 제거, 무게 감소
	// 3. 1,2가 아닌경우
	// 4. 무게가 초과할 경우 : 큐에 0을 추가(무게 영향없음), 시간 추가
	// 5. 4가 아닌 경우 : 1과 같은 작업
	for (int i = 0; i < truck.size(); i++)
	{
		while (1)
		{
			// 1
			if (q.empty())
			{
				q.push(truck[i]);
				sum += truck[i];
				res++;
				break;
			}
			// 2
			else if (q.size() == w)
			{
				sum -= q.front();
				q.pop();
			}
			// 3
			else
			{
				// 5
				if (sum + truck[i] <= L)
				{
					q.push(truck[i]);
					sum += truck[i];
					res++;
					break;
				}
				// 4
				else
				{
					q.push(0);
					res++;
				}
			}
		}
	}
	// 총 시간 : 누적 시간 + 마지막 트럭이 건너는 시간(다리 길이)
	cout << res + w << '\n';
}