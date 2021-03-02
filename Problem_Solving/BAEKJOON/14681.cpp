#include <iostream>

using namespace std;

int main(void)
{
	int x, y;
	cin >> x >> y;
	int res = x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
	cout << res << '\n';
}