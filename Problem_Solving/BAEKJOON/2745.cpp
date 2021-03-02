#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int n;
	cin >> n;
	int k = 1;
	int res = 0;
	// 뒷 자리수부터 역순으로 체크
	for (int i = s.size() - 1; i >= 0; i--)
	{
		// 현재 자릿수를 10진수로 변환
		int t;
		if (s[i] >= 'A') t = s[i] - 'A' + 10;
		else t = s[i] - '0';
		// 값 누적
		res += k * t;
		k *= n; // 자릿수 증가
	}
	cout << res;
}
