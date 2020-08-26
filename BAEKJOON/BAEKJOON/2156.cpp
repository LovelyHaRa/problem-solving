#include<iostream>

using namespace std;

int wine[10000];
int d[10000];

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> wine[i];
	/* 계단오르기랑 비슷
	   현재 와인위치에서
	   아예 안마시는 경우
	   현재 와인과 이전의 와인을 마시는 경우
	   현재 와인과 두번째 전 와인을 마시는 경우 중
	   최댓값을 저장한다.
	*/
	d[0] = wine[0];
	d[1] = d[0] + wine[1];
	d[2] = max(max(d[1], wine[2] + wine[1]), wine[2] + d[0]);
	for (int i = 3; i < n; i++)
		d[i] = max(max(d[i - 1], wine[i] + d[i - 2]), wine[i] + wine[i - 1] + d[i - 3]);
	cout << d[n - 1] << endl;
}