// 그리디 알고리즘
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	vector<vector<int>> meeting;
	cin >> n;
	meeting.resize(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		/**
		* 2차원 백터 정렬시 첫 열을 기준으로 정렬하므로 위치를 바꿔서 입력받음
		*/
		meeting[i].push_back(b);
		meeting[i].push_back(a);
	}
	/*
	1. 회의가 끝나는 시간을 기준으로 오름차순 정렬한다.
	2. 첫번째 시간은 무조건 넣고본다(그리디 알고리즘 특성, res = 1)
	3. 순차 탐색한다.
	4. 현재 회의가 끝나는 시간보다 다음 회의 시작시간이 크거나 같으면 회의가능
	5. 회의가 가능하면 그지점부터 3~4를 반복한다.
	6. 순차탐색이 끝까지 도달하면 정답을 출력한다.
	*/
	// 1.
	sort(meeting.begin(), meeting.end());
	// 2.
	int k = 0, res = 1;
	while (1)
	{
		int i;
		// 3.
		for (i = k + 1; i < n; i++)
		{
			// 4.
			if (meeting[k][0] <= meeting[i][1])
			{
				// 5.
				res++;
				k = i;
				break;
			}
		}
		// 6.
		if (i == n)
			break;
	}
	cout << res << '\n';
}
