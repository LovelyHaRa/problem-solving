#include<iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	int count = 0;
	while (N != 1)
	{
		!(N % 3) ? N /= 3 : !(N % 2) ? N /= 2 : N--;
		count++;
	}
	cout << count << endl;
}