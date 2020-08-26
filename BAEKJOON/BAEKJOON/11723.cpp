#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(void)
{
	// 입력 수가 많아서 시간초과 났음
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<int> s;
	int m;
	cin >> m;
	while (m--)
	{
		string op;
		cin >> op;
		int x;
		// add, all
		if (op[0] == 'a')
		{
			// add
			if (op[1] == 'd')
			{
				cin >> x;
				s.insert(x);
			}
			// all
			else
			{
				for (int i = 1; i <= 20; i++)
					s.insert(i);
			}
		}
		// remove, check
		else if (op[0] == 'r' || op[0] == 'c')
		{
			cin >> x;
			// 원소 포함 여부 확인
			if (s.find(x) != s.end())
			{
				// remove면 삭제, check이면 1 출력
				if (op[0] == 'r')
					s.erase(s.find(x));
				else
					cout << "1\n";
			}
			// check 이고 원소가 없으면 0 출력
			else if (op[0] == 'c')
				cout << "0\n";
		}
		// toggle
		else if (op[0] == 't')
		{
			cin >> x;
			// 있으면 삭제
			if (s.find(x) != s.end())
				s.erase(s.find(x));
			else
				s.insert(x);
		}
		// empty
		else if (op[0] == 'e')
			s.clear();
	}
}