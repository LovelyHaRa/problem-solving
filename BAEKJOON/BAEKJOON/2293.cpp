#include<iostream>

using namespace std;

int main(void)
{
	int c[101], d[10001] = { 0 }; // 동전 종류, 경우의수 저장
	int n, k; // n개의 동전, k를 만들수 있는 경우
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> c[i]; // 동전 종류 입력
	d[0] = 1;
	/* 첫번째 동전만 사용한 경우~ 
	   첫번째 부터 n번째 동전을 사용한 경우를 이용하여 계산
	   점화식
	   D(i,k)={	D(i,k-C(i))+D(i-1,k) (C(i)<=k)
				D(i-1,k) (C(i)>K }
	*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = c[i]; j <= k; j++)
			d[j] += d[j - c[i]];
	}
	cout << d[k] << endl;	
}