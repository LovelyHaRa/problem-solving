#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
	int N, K;
	while (1)
	{
		scanf("%d %d", &N, &K);
		if (!N && !K) break;
		long long res = 1;
		K > N - K ? K = N - K : K;
		for (int i = 1; i <= K; i++)
		{
			res *= N;
			res /= i;
			N--;
		}
		cout << res << endl;
	}
}
