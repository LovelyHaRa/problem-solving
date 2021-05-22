#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	while (1)
	{
		string s;
		getline(cin, s);
		if (s.empty()) break;
		int counta = 0, countA = 0, countn = 0, countb = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z') counta++;
			else if (s[i] >= 'A' && s[i] <= 'Z') countA++;
			else if (s[i] >= '0' && s[i] <= '9') countn++;
			else if (s[i] == ' ') countb++;
		}
		cout << counta << ' ' << countA << ' ' << countn << ' ' << countb << '\n';
	}
}
