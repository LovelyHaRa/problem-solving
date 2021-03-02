#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	set<string> s; // 들어보지 못한 사람 집합
	// 들어보지 못한 사람 추가
	while (n--)
	{
		string str;
		cin >> str;
		s.insert(str);
	}
	set<string> ss; // 듣도 보도 못한 사람 집합
	// 듣도 보도 못한 사람 추가
	while (m--)
	{
		string str;
		cin >> str;
		// 들어보지 못한 사람이면 추가
		if (s.find(str) != s.end())
			ss.insert(str);			
	}
	// 출력
	cout << ss.size() << '\n';
	for (auto it = ss.begin(); it != ss.end(); it++)
		cout << *it << '\n';
}