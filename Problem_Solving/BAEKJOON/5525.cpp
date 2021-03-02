#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	int n, m;
	string s;
	cin >> n >> m >> s;
	int cnt = 0, res = 0; // 연속으로 찾은 개수, 패턴 일치 개수
	for (int i = 0; i < m - 2; i++)
	{
		// IOI 패턴을 찾는다
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			cnt++; // 연속으로 찾은 개수 증가
			// 패턴 개수와 연속으로 찾은 개수가 같아지면
			if (cnt == n)
			{
				res++; // 패턴 일치 개수 증가
				cnt--; // 연속으로 찾은 개수를 지속 시키기 위해서 하나 감소
			}
			i++; // 한칸 건너뛰기(다음은 무조건 O 이기 떄문)
		}
		else cnt = 0; // 연속으로 찾은 개수 초기화
	}
	cout << res << '\n'; // 결과 출력
}