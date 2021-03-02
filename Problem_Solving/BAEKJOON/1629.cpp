// 분할정복
#include <iostream>

using namespace std;

long long a, b, c;

// 일반적인 제곱 재귀는 O(N)
// 분할 정복을 이용하여 O(logN)으로 개선할 수 있다.
long long multi(int a, int b)
{
	if (!b)
		return 1;
	if (b == 1)
		return a;
	if (b % 2)
		return multi(a, b - 1)*a; // 홀수면 a^(b-1)*a로 분할 가능
	long long h = multi(a, b / 2); // 짝수면 a^(b/2)*a^(b/2)로 분할 가능
	// 계산 중간에 나눈 나머지랑 모든 계산이 끝난 뒤 나눈 나머지는 같다
	h %= c;
	return (h*h) % c;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;
	
	cout << multi(a, b) % c << '\n';

}
