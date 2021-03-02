#include<iostream>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
int d[1000001]; // 10^6 크기의 동적프로그래밍 배열

int main(void)
{	
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1; //N-1의 개수 +1
		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1); // N/2+1 가 더 작으면 교체
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1); // N/3+1 가 더 작으면 교체
	}
	cout << d[n] << endl;
}
