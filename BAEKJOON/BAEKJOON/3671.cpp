// 브루트포스
// 프로그래머스 풀이 참조
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

const int MAX = 1e7;
int prime[MAX];
void setPrime()
{
	prime[0] = prime[1] = -1;
	for (int i = 2; i <= MAX; i++)
		prime[i] = i;
	for (int i = 2; i*i <= MAX; i++)
	{
		if (prime[i] == i)
		{
			for (int j = i * i; j <= MAX; j+=i)
			{
				if (prime[j] = j)
					prime[j] = i;
			}
		}
	}
}

int main(void)
{
	int c;
	cin >> c;
	setPrime();
	while (c--)
	{
		string number;
		cin >> number;
		vector<int> num;
		map<int, bool> visited;
		int count = 0;
		for (int i = 0; i < number.length(); i++)
			num.push_back(number[i] - '0');
		for (int i = 1; i <= num.size(); i++)
		{
			sort(num.begin(), num.end());
			do
			{
				string s;
				for (int j = 0; j < i; j++)
				{
					if (s.empty() && num[j] == '0')
						continue;
					s += num[j] + '0';
				}

				if (s.empty())
					continue;

				int k = stoi(s);

				if (visited.count(k))
					continue;
				visited[k] = true;

				if (k == prime[k])
					count++;
			} while (next_permutation(num.begin(), num.end()));
		}
		cout << count << '\n';
	}
}