#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int ceil(int a, int b) { return (a + b - 1) / b; } // a/b 값을 올림한다.
int max(int a, int b) { return a > b ? a : b; }

vector<int> solve(const vector<int>& recipe, const vector<int>& put)
{
	int n = recipe.size();
	// recipe의 모든 수에 대해 최대 공약수를 구한다
	int b = recipe[0];
	for (int i = 1; i < n; i++)
		b = gcd(b, recipe[i]);
	// 최소 1배수는 만들어야한다
	int a = b;
	// put[i]*b/recipe[i]의 최대값을 계산한다
	for (int i = 0; i < n; i++)
		a = max(a, ceil(put[i] * b, recipe[i]));
	// a/b 배로 넣는다
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = recipe[i] * a / b - put[i];
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> recipe(n), put(n);
		for (int i = 0; i < n; i++)
			cin >> recipe[i];
		for (int i = 0; i < n; i++)
			cin >> put[i];
		vector<int> res = solve(recipe, put);
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << ' ';
		cout << '\n';
	}
}
