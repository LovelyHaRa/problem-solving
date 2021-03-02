// 그리디 알고리즘
#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int a[1000], b[1000]; // 데이터, 중간값 저장
	int n, min = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	/*
	1. 오름차순 정렬
	2. 각각 배열요소의 누적합을 저장(b)
	3. b의 요소를 모두 더함(min)
	*/
	sort(a, a + n);
	min = b[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		b[i] = b[i-1] + a[i]; // 누적합 계산
		min += b[i]; // 결과값 계산
	}
	cout << min << '\n';
}
