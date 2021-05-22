#include<iostream>
#include<string>
#include<vector>

using namespace std;

char candy[4] = { 'C','P','Z','Y' };

// swap
void swap(vector<string>&arr, int p, int q, int r, int s)
{
	char t = arr[p][q];
	arr[p][q] = arr[r][s];
	arr[r][s] = t;
}

// 행 검사
int eatRowCandy(const vector<string>&arr, int row)
{	
	int max = 0, cnt = 0;
	// 캔디 종류만큼 반복
	for (int i = 0; i < 4; i++)
	{
		// 연속된 카운트 저장
		cnt = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (candy[i] == arr[j][row])
				cnt++;
			else
			{
				max = max < cnt ? cnt : max;
				cnt = 0;
			}
		}
		// 카운트 최대값 갱신
		max = max < cnt ? cnt : max;
	}
	// 최대값 리턴
	return max;
}

// 열 검사
int eatColCandy(const vector<string>&arr, int col)
{
	int max = 0, cnt = 0;
	// 캔디 종류만큼 반복
	for (int i = 0; i < 4; i++)
	{
		// 연속된 카운트 저장
		cnt = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (candy[i] == arr[col][j])
				cnt++;
			else
			{
				max = max < cnt ? cnt : max;
				cnt = 0;
			}
		}
		// 카운트 최대값 갱신
		max = max < cnt ? cnt : max;
	}
	// 최대값 리턴
	return max;
}

int main(void)
{
	int n;
	cin >> n;
	vector<string> bomboni(n);
	for (int i = 0; i < n; i++)
		cin >> bomboni[i];
	int max = -1;
	// 1. 완전탐색
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt;
			// 2. 행끼리 교환
			if (i + 1 < n) // 마지막 행은 교환 안함
			{
				// 3. 현재칸, 밑칸 교환
				swap(bomboni, i, j, i + 1, j);
				// 4. 현재칸 행 검사 후 최대값 갱신
				cnt=eatRowCandy(bomboni, j);
				max = max < cnt ? cnt : max;
				// 5. 현재칸 열 검사 후 최대값 갱신
				cnt = eatColCandy(bomboni, i);
				max = max < cnt ? cnt : max;
				// 6. 밑칸 열 검사 후 최대값 갱신
				cnt = eatColCandy(bomboni, i + 1);
				max = max < cnt ? cnt : max;
				// 7. 원상 복구
				swap(bomboni, i, j, i + 1, j);
			}
			// 8. 열끼리 교환
			if (j + 1 < n) // 마지막 열은 교환 안함
			{
				// 9. 현재칸, 옆칸 교환
				swap(bomboni, i, j, i, j + 1);
				// 10. 현재칸 행 검사 후 최대값 갱신
				cnt=eatRowCandy(bomboni, j);
				max = max < cnt ? cnt : max;
				// 11. 옆칸 행 검사 후 최대값 갱신
				cnt = eatRowCandy(bomboni, j + 1);
				max = max < cnt ? cnt : max;
				// 12. 현재칸 열 검사 후 최대값 갱신
				cnt = eatColCandy(bomboni, i);
				max = max < cnt ? cnt : max;
				// 13. 원상 복구
				swap(bomboni, i, j, i, j + 1);
			}
		}
	}
	// 14. 최대값 출력
	cout << max;
}
