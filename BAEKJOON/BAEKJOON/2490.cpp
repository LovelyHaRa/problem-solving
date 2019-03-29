#include<iostream>

using namespace std;

int main(void)
{
	int n, k;
	for (int i = 0; i < 3; i++)
	{
		k = 0;
		for (int j = 0; j < 4; j++)
		{	
			cin >> n;
			k = n ? k+1 : k;
		}
		cout << (char)(k == 4 ? 'E' : 'D' - k) << endl;
	}
}