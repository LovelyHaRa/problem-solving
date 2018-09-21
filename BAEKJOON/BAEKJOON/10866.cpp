#include<iostream>
#include <string>
#define M 10000
using namespace std;

int main(void)
{
	int N, data;
	int deque[M], size = 0, front = 0, rear = 0;
	string c;
	cin >> N;
	while (N > 0)
	{
		cin >> c;
		char a = c.at(1);
		if (a == 'u')
		{
			cin >> data;
			if (c.at(5) == 'f')
			{
				size != M ? deque[front--] = data : data = -1;
				front < 0 ? front = M - 1 : -1;
			}
			else
			{
				if (size < M)
				{
					rear = ++rear%M;
					size != M ? deque[rear] = data : data = -1;
				}
			}
			data > 0 ? size++ : 0;
		}
		else if (a == 'o')
		{
			data = -1;
			if (c.at(4) == 'f')
			{
				if (size)
				{
					front = ++front%M;
					data = deque[front];
				}
			}
			else
			{
				size ? data = deque[rear--] : data = -1;
				rear < 0 ? rear = M - 1 : -1;
			}
			data > 0 ? size-- : 0;
			cout << data << endl;
		}
		else if (a == 'i')
			cout << size << endl;
		else if (a == 'm')
			cout << !(bool)size << endl;
		else if (a == 'r')
			cout << (size ? deque[(front + 1) % M] : -1) << endl;
		else
			cout << (size ? deque[rear] : -1) << endl;
		N--;
	}
}