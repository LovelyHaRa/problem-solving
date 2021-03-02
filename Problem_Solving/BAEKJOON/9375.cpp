#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(void)
{
	int T, n;
	cin >> T;
	for (; T > 0; T--)
	{
		map<string, int> F;
		string item, wear;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> item >> wear;
			F[wear]++;
		}
		int result = 1;
		for (auto i : F)
			result *= (i.second + 1);
		cout << result - 1 << endl;
	}
	
}