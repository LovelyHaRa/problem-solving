#include<iostream>

using namespace std;

// 잔금 처리를 시뮬레이션 한다.
double balance(double amount, int duration, double rates, double monthlyPayment)
{
	double balance = amount; // 대출 금액부터 시작
	// 월마다 상환
	for (int i = 0; i < duration; i++)
	{
		balance *= (1.0 + (rates / 12) / 100); // 잔금 불리기
		balance -= monthlyPayment; // 상환하기
	}
	return balance; // 남은 대출금
}

// 이분 탐색으로 한달에 상환해야할 금액을 구한다
double payment(double amount, int duration, double rates)
{
	// 최소: 아예 갚지 않는 경우(0), 최대: 다음달에 모든 돈을 상환하는 경우
	double lo = 0, hi = amount * (1.0 + (rates / 12) / 100);
	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2.0;
		// 대출금을 모두 갚을 수 있으면
		if (balance(amount, duration, rates, mid) <= 0)
			hi = mid; // 최솟값 탐색
		else
			lo = mid; // 최댓값 탐색
	}
	return hi; // 갚을 수 있는 값을 반환
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		double n, p;
		int m;
		cin >> n >> m >> p;
		cout.precision(12);
		cout << fixed << payment(n, m, p) << '\n';
	}
}