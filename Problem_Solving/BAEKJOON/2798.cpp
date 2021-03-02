#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	vector<int> jack, c;
	int n, m;
	int sum, max = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		jack.push_back(k);
	}

	for (int i = 0; i < n-3; i++)
		c.push_back(0);
	for (int i = 0; i < 3; i++)
		c.push_back(1);

	do
	{
		sum = 0;
		for (int i = 0; i < n; i++)
			sum = c[i] ? sum + jack[i] : sum;
		if (sum > m) continue;
		max = max < sum ? sum : max;
		if (max == m)
			break;
		
	} while (next_permutation(c.begin(), c.end()));
	cout << max << endl;
}