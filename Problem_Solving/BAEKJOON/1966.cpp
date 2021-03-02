#include<iostream>
using namespace std;
class Printer
{
public:
	int num;
	int impor;
};
int main(void)
{
	Printer *p;
	int T, N, M;
	cin >> T;
	while (T > 0)
	{
		int front = 0, rear = 0;
		p = new Printer[200];
		cin >> N >> M;
		for (rear = 0; rear < N; rear++)
		{
			cin >> p[rear].impor;
			p[rear].num = rear;
		}
		int res = 0;
		while (front != rear)
		{
			int i;
			for (i = front + 1; i < rear; i++)
			{
				if (p[i].impor > p[front].impor)
					break;
			}
			if (i < rear)
				p[rear++] = p[front++];
			else
			{
				res++;
				if (p[front++].num == M)
					break;
			}
		}
		cout << res << endl;
		T--;
	}
}
