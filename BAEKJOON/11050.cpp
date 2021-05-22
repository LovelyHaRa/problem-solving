#include<iostream>
using namespace std;

int C(int n, int k)
{
	if (k == 1)
		return n;
	else if (k == 0 || k==n)
		return 1;
	return C(n - 1, k) + C(n - 1, k - 1);
}

int main(void)
{
	int N, K;
	cin >> N >> K;
	cout << C(N, K) << endl;
}
