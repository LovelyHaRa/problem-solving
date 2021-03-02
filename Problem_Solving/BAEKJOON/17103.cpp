#include<iostream>
#include<vector>

using namespace std;

vector<int> prime;

// 에라토스테네스 체를 이용하여 소수 테이블 구성
void setPrime(int n)
{
	prime.resize(n + 1);
	prime[0] = prime[1] = 1;
	for (int i = 2; i <= n; i++) prime[i] = i;
	for (int i = 2; i*i <= n; i++)
	{
		if (prime[i] == i)
		{
			for (int j = i * i; j <= n; j += i)
				if (prime[j] == j) prime[j] = i;
		}
	}
}

int main(void)
{
	setPrime(1000000); // 소수 테이블 만들기
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int cnt = 0;
		// 받은 수는 짝수이기 때문에 n/2 가 반드시 나누어 떨어짐
		// n/2 이후의 값은 순서만 바뀔 뿐 동일함
		for (int i = 2; i <= (n / 2); i++)
		{
			// i, n-i 가 둘다 소수이면 카운트
			if (prime[i] == i && prime[n - i] == (n - i))
				cnt++;
		}
		cout << cnt << '\n';
	}
}
