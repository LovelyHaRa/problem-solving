#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n, b;
	cin >> n >> b;
	string res;
	while (n)
	{
		// 1. 진수로 나눈 나머지 추출
		int k = n % b;
		// 2. 나머지가 10이상이면 알파벳 저장
		if (k >= 10)
			res += k - 10 + 'A';
		// 3. 그렇지 않으면 숫자 저장
		else
			res += k + '0';
		// 4. 진수로 나누기
		n /= b;
	}
	// 역순 출력
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];
}
