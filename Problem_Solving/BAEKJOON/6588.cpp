#include<iostream>
#include<vector>

using namespace std;

vector<int> prime(1000001);
vector<int> setprime;

// 에라토스테네스의 체
void getPrime()
{
	for (int i = 2; i < prime.size(); i++)
		prime[i] = i;
	for (int i = 2; i*i < prime.size(); i++)
	{
		if (!prime[i])
			continue;
		for (int j = i * 2; j < prime.size(); j += i)
			prime[j] = 0;
	}
}

int main(void)
{
	// 이걸 안해서 타임아웃
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 소수 테이블 생성
	getPrime();
	// 소수 집합을 따로 생성
	for (int i = 3; i < prime.size(); i++)
	{
		if (prime[i]) setprime.push_back(i);
	}
	while (1)
	{
		// 입력
		int n;
		cin >> n;
		if (!n) break;
		int i;
		// 소수 집합 탐색(소수는 n/2 까지만 탐색되면 됨)
		for (i = 0; i < setprime.size() && setprime[i] <= n / 2; i++)
		{
			// n-setprime[i] 가 소수이면 b-a가 최대가 되는 합 생성 가능
			if (prime[n - setprime[i]])
			{
				cout << n << " = " << setprime[i] << " + " << n - setprime[i] << '\n';
				break;
			}
		}
		// 만족하는 데이터 없음
		if (i == setprime.size() || setprime[i] > n / 2)
			cout << "Goldbach's conjecture is wrong.\n";

	}
}