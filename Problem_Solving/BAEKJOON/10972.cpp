#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> k(n);
	for (int i = 0; i < n; i++)
		cin >> k[i];
	if (!next_permutation(k.begin(), k.end()))
		cout << "-1";
	else
	{
		for (int i : k)
			cout << i << ' ';
	}
}