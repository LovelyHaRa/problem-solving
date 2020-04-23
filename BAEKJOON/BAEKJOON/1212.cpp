#include<iostream>
#include<string>

using namespace std;

// 앞자리를 0으로 채우지 않고 변환
string nonZeroTransform(char a)
{
	switch (a) 
	{
	case '0': return "0";
	case '1': return "1";
	case '2': return "10";
	case '3': return "11";
	case '4': return "100";
	case '5': return "101";
	case '6': return "110";
	case '7': return "111";
	}
	return "";
}

// 앞자리를 0으로 채우고 변환
string zeroTransform(char a)
{
	switch (a)
	{
	case '0': return "000";
	case '1': return "001";
	case '2': return "010";
	case '3': return "011";
	case '4': return "100";
	case '5': return "101";
	case '6': return "110";
	case '7': return "111";
	}
	return "";
}

int main(void)
{
	string s;
	cin >> s;
	string res; // 결과 이진수
	res += nonZeroTransform(s[0]); // 맨 앞자리 숫자는 변환 후에 0으로 시작하면 안됨
	// 나머지 숫자는 앞자리를 0으로 채운 이진수를 결과 배열에 누적
	for (int i = 1; i < s.size(); i++)
		res += zeroTransform(s[i]);
	cout << res;
}