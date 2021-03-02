#include<iostream>
#include<string>

using namespace std;

string reverse(string::iterator& it)
{
	char head = *it; // 첫글자
	++it; // 반복자 증가
	if (head == 'b' || head == 'w')
		return string(1, head); // b, w 1개 단위는 뒤집어도 같음
	// x이면 4분면 모두 재귀호출
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);
	// 순서를 반전 시켜 리턴 (3,4,1,2)
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		string::iterator it = s.begin();
		// 반복자 포인터를 파라미터로 함으로써, 포인터 위치를 매번 갱신 가능
		cout << reverse(it) << '\n';
	}
}