#include<iostream>
#include<list>

using namespace std;

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, k;
		cin >> n >> k;
		list<int> survivors;
		for (int i = 1; i <= n; i++) survivors.push_back(i); // 번호 삽입
		list<int>::iterator kill = survivors.begin(); // 1번 사람부터 자결
		// 두명 살아 남을 때 까지 반복
		while (n > 2)
		{
			kill = survivors.erase(kill); // 현재 사람 자결, 포인터는 다음 사람을 가리킨다
			// 원형 리스트 처럼 동작
			if (kill == survivors.end()) kill = survivors.begin();
			n--; // 사람 수 감소
			// k-1사람까지 포인터 증가(다음사람을 이미 가리키고 있으므로)
			for (int i = 0; i < k - 1; i++)
			{
				kill++; // 포인터 증가
				// 원형 리스트 처럼 동작
				if (kill == survivors.end()) kill = survivors.begin();
			}
		}
		// 남아있는 두사람 출력
		cout << survivors.front() << ' ' << survivors.back() << '\n';
	}
}
