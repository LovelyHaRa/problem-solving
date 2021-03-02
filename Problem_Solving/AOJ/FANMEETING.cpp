#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> mutiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	}
	return c;
}

void addTo(vector<int>& a, vector<int>& b, int k)
{
	int len = max(a.size(), b.size() + k);
	a.resize(len, 0);
	b.resize(len, 0);
	for (int i = 0; i < len - k; i++)
		a[i + k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b)
{
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < b.size(); i++)
		a[i] -= b[i];
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 100) return mutiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		string members, fans;
		cin >> members;
		cin >> fans;
		int n = members.size(), m = fans.size();
		vector<int>a(n), b(m);
		for (int i = 0; i < n; i++) a[i] = (members[i] == 'M');
		for (int i = 0; i < m; i++) b[m - i - 1] = (fans[i] == 'M');
		vector<int> c = karatsuba(a, b);
		int allHugs = 0;
		for (int i = n - 1; i < m; i++)
		{
			if (!c[i])
				++allHugs;
		}
		cout << allHugs << '\n';
	}
}