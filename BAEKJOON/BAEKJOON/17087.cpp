#include<iostream>

using namespace std;

// 최대공약수 구하기
int gcd(int a, int b)
{
	if (a > b) return gcd(a%b, b);
	if (!a) return b;
	return gcd(b%a, a);
}

int main(void)
{
	int n, s;
	cin >> n >> s;
	// 초기값 결정
	int min;
	cin >> min;
	min = min > s ? min - s : s - min; // 차이의 절대값 저장
	n--;
	while (n--)
	{
		// 두번째 부터 비교
		int a;
		cin >> a;
		int k = a > s ? a - s : s - a; // 차이의 절대값 저장
		int g = gcd(min, k); // 최소값과 현재 값의 최대공약수 구하기
		min = min > g ? g : min; // 최소값 갱신
	}
	cout << min;
}