#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int a[9];
	int sum = 0;
	// 1. 입력과 동시에 총 합계 구하기
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}	
	int flag = 0; // 탈출 플래그
	// 2. 총합-선택한 두수의 합==100 이면 조건 만족
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1;j < 9; j++)
		{
			if (sum - a[i] - a[j] == 100)
			{
				flag = 1; // 탈출 플래그
				a[i] = a[j] = -1; // 정렬시 맨 앞에 두기 위해
				break;
			}
		}
		// 플래그 검사
		if (flag)
			break;
	}
	// 3. 정렬
	sort(a, a + 9);
	// 4. 앞의 두 수는 제외시킨 채로 출력(-1로 설정)
	for (int i = 2; i < 9; i++)
		cout << a[i] << '\n';
	
}
