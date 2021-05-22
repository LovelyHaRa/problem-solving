#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool compare(const string &s1, const string &s2)
{
	if (s1.size() == s2.size())
		return s1 < s2;
	return s1.size() < s2.size();
}

int main(void)
{
	vector<string> data;
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		data.push_back(str);
	}
	
	sort(data.begin(), data.end(), compare);
	vector<string>::iterator iter;
	vector<string>::iterator end_iter = unique(data.begin(), data.end());

	for (iter = data.begin(); iter != end_iter; iter++)
		cout << *iter << endl;
}
