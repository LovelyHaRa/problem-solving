#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> table;

// 팀의 능력치 계산
int calcSkill(const vector<int>& t)
{
	int ret = 0;
	for (int i = 0; i < t.size(); i++)
		for (int j = i + 1; j < t.size(); j++)
			ret += table[t[i]][t[j]] + table[t[j]][t[i]];
	return ret;
}

int abs(int a) { return a >= 0 ? a : -a; }

// A팀, B팀의 수가 결정 되었을 때 능력치의 치이의 최솟값을 반환
int process(int a, int b)
{
	vector<vector<int>> team1, team2;
	vector<int> t1(a), t2(b);

	// 조합을 계산하기 위한 세팅
	vector<bool> c(n);
	fill(c.end() - b, c.end(), true);

	int idx1, idx2;
	// 조합을 이용하여 모든 경우의 수 계산
	do
	{
		idx1 = idx2 = 0;
		for (int i = 0; i < n; i++)
		{
			// 어느 팀에 합류할지 결정
			if (!c[i])
				t1[idx1++] = i;
			else
				t2[idx2++] = i;
		}
		team1.push_back(t1);
		team2.push_back(t2);
	} while (next_permutation(c.begin(), c.end()));

	// 능력치 차이의 최솟값을 계산
	int ret = 1987654321;
	for (int i = 0; i < team1.size(); i++)
		ret = min(ret, abs(calcSkill(team1[i]) - calcSkill(team2[i])));
	return ret;
}

int main(void)
{
	cin >> n;
	table.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> table[i][j];
	int res = 1987654321;
	int mod = n % 2;
	// 모든 경우의 수 계산
	// 어떤 경우든지 차이의 최솟값은 0이기 때문에 res가 0이 되면 바로 종료
	for (int i = 0; i < n / 2; i++)
	{
		res = min(res, process(n / 2 + i + mod, n / 2 - i));
		if (!res) break;
		res = min(res, process(n / 2 + i, n / 2 - i + mod));
		if (!res) break;
		res = min(res, process(n / 2 - i + mod, n / 2 + i));
		if (!res) break;
		res = min(res, process(n / 2 - i, n / 2 + i + mod));
		if (!res) break;
	}
	cout << res << '\n';
}
