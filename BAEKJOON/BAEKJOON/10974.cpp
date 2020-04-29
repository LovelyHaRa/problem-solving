#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> k(n);
	for (int i = 0; i < n; i++) k[i] = i + 1;
	do
	{
		for (int i = 0; i < n; i++)
			cout << k[i] << ' ';
		cout << '\n';
	} while (next_permutation(k.begin(), k.end()));
}