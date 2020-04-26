#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	string res; // 결과 이진수
	// 이진수 변환 배열
	string nonZeroBin[] = { "0","1","10","11","100","101","110","111" };
	string zeroBin[] = { "000","001","010","011","100","101","110","111" };
	res += nonZeroBin[s[0]-'0']; // 맨 앞자리 숫자는 변환 후에 0으로 시작하면 안됨
	// 나머지 숫자는 앞자리를 0으로 채운 이진수를 결과 배열에 누적
	for (int i = 1; i < s.size(); i++)
		res += zeroBin[s[i]-'0'];
	cout << res;
}