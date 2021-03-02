// 그리디 알고리즘
#include<iostream>

using namespace std;

int main(void)
{
	int n, k;
	int coin[10];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	int res = 0, index = n;
	// 1. 큰 단위의 동전부터 순차적으로 탐색
	// 2. 동전값이 k보다 크면 다음 동전 탐색
	// 3. 작으면 k를 동전값으로 나눈 몫이 개수이므로 누적시킴
	// 4. 3에서 계산한 나머지를 k에 다시 저장
	// 5. k가 0이되거나 탐색이 끝나면 결과 출력
	while (index--)
	{
		if (k == 0)
			break;
		else if (coin[index] > k)
			continue;
		res += k / coin[index];
		k %= coin[index];
	}
	cout << res << '\n';
}
