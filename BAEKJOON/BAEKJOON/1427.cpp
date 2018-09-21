#include<iostream>
using namespace std;

int main(void)
{
	char data[11];
	cin >> data;
	for (int i = 0; data[i+1]!='\0'; i++)
		for (int j = i + 1; data[j] != '\0'; j++)
			if (data[i]-'0' < data[j]-'0')
			{
				char t = data[i];
				data[i] = data[j];
				data[j] = t;
			}
	cout << data;
}