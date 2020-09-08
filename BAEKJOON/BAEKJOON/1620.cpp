#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> dic; // key: 포켓몬, value: 번호
	vector<string> dic2; // key: 번호, value: 포켓몬
	// 사전 생성
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		dic[s] = i + 1;
		dic2.push_back(s);
	}
	// 사전 검색
	while(m--)
	{
		string s;
		cin >> s;
		// 숫자이면
		if (s[0] >= '0' && s[0] <= '9')
			cout << dic2[stoi(s) - 1] << '\n';
		// 포켓몬이면
		else
			cout << dic[s] << '\n';
	}
}