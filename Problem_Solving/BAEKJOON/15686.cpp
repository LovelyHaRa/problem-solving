#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> home, chicken; // 집, 치킨집 2d 백터 배열
bool selected[13];										// 선택한 치킨집
int res = 1275;												// 가능한 입력 데이터 최대 [맨하탄 거리] * [치킨 집 수] + 1

// 모든 경우에 대해 m개의 치킨집을 순차적으로 선택했을 때
// 치킨 거리의 최솟값을 res에 저장하는 함수(DFS)
void getDist(int current, int count)
{
	// 치킨집 번위를 벗어날 경우 리턴
	if (current > chicken.size())
		return;
	// 선택이 완료된 경우 치킨 거리 계산
	if (count == m)
	{
		int sumDist = 0; // 도시의 치킨 거리
		// 1. 각 집에 대해서
		for (int i = 0; i < home.size(); i++)
		{
			int dist = 99; // 가능한 입력 데이터의 최대 [맨하탄 거리] + 1
			// 2. 모든 치킨 집에 대해 탐색하고
			for (int j = 0; j < chicken.size(); j++)
			{
				// 3. 선택된 치킨 집에 대해서 치킨 거리를 구한다
				if (selected[j])
				{
					int dx = abs(home[i].first - chicken[j].first);
					int dy = abs(home[i].second - chicken[j].second);
					dist = min(dist, dx + dy); // 치킨 거리의 최솟값을 저장한다
				}
			}
			sumDist += dist; // 치킨 거리의 최솟값을 누적시켜 도시의 치킨 거리를 구한다
		}
		res = min(res, sumDist); // 도시의 치킨 거리의 최솟값을 갱신한다
		return;
	}

	// 현재 치킨 집을 선택할 경우
	selected[current] = 1;
	getDist(current + 1, count + 1);
	// 현재 치킨 집을 선택하지 않을 경우
	selected[current] = 0;
	getDist(current + 1, count);
}

int main(void)
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			if (x == 1)
				home.push_back({i, j}); // 집 죄표 저장
			else if (x == 2)
				chicken.push_back({i, j}); // 치킨집 좌표 저장
		}
	// 첫번 째 치킨 집 부터 탐색한다
	getDist(0, 0);
	cout << res << '\n';
}