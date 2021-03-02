#include<iostream>

using namespace std;

int main(void)
{
	int x, res = 0;
	cin >> x;
	/*
	  x를 이진수로 바꿧을 때 1의 개수
	*/
	for (; x; x /= 2)
		res += x % 2;
	cout << res;
}
