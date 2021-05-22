#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
	int n, a, b, res = 1, t;
	cin >> n >> a >> b;
	/*
	  n강 토너먼트 라운드 수 : log2(n)의 올림수
	  a,b 의 대소 판별
	  두 번호의 차이가 1이면서 작은 값이 홀수이면
	  대결이 성사된 것임
	  그렇지 않으면 두 번호를 +1 하고 2로 나눠서
	  다음 라운드의 번호를 구함
	*/
	t = (int)ceil(log2(n));
	while ((t+1)!=res)
	{
		int max = a > b ? a : b;
		int min = a < b ? a : b;
		if (min % 2 && max - min == 1)
			break;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		res++;
	}
	if (res > t)
		cout << "-1" << endl;
	else
		cout << res << endl;
}
