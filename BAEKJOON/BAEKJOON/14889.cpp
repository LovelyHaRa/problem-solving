#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int table[20][20];
int N;
vector<vector<int>> team1;
vector<vector<int>> team2;

int calcSkill(vector<int> v)
{
	int ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
			ret += table[v[i]][v[j]] + table[v[j]][v[i]];
	}
	return ret;
}

void process(vector<int> v, int r)
{	
	vector<int> t1(r);
	vector<int> t2(r);

	vector<bool> c(N);
	fill(c.end() - r, c.end(), true);
	int idx1, idx2;
	do
	{
		idx1 = idx2 = 0;
		for (int i = 0; i < N; i++)
		{
			if (c[i])
				t1[idx1++] = *(v.begin() + i);
			else
				t2[idx2++] = *(v.begin() + i);
		}
		team1.push_back(t1);
		team2.push_back(t2);
		
	} while (next_permutation(c.begin(), c.end()));
	
	int res = 0, _min = 1987654321;
	for (int i = 0; i < team1.size(); i++)
	{
		res = abs(calcSkill(team1[i]) - calcSkill(team2[i]));
		_min = res < _min ? res : _min;
		if (!_min)
			break;
	}
	cout << _min << '\n';
}



int main(void)
{
	vector<vector<int>> resVec;
	vector<int> num;
	int _min = 1987654321;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		num.push_back(i);
		for (int j = 0; j < N; j++)
			cin >> table[i][j];
	}
	process(num, N / 2);
}