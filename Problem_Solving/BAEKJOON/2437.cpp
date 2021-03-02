#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int n;
	int k[1000], c=0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> k[i];
	/*
	무게를 오름차순 정렬
	c:0~c까지 측정 가능
	c+1<k[i]를 만족하면
	c+1 부터 k[i] 사이의 무게는 측정할 수 없음
	*/
	sort(k, k + n);
	for (int i = 0; i < n; i++)
	{
		if (c + 1 < k[i])
			break;
		c += k[i];
	}
	cout << c + 1 << endl;
}