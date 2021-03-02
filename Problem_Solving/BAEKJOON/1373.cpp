#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void)
{
	string s; // 입력 데이터
	cin >> s;
	int k = 1; // 자릿수 (1,2,4)
	vector<int> res; // 8진수 배열
	int t = 0; // 구역별 8진수 저장
	// 1. 역순으로 탐색
	for (int i = s.size() - 1; i >= 0; i--)
	{
		t += k * (s[i] - '0'); // 2. 자릿수를 곱해 8진수 만들기
		k *= 2; // 3. 자릿수 *2
		// 4. 3자리마다 8진수 배열에 저장
		if (k > 4)
		{
			res.push_back(t); // 배열에 누적
			// 초기화
			k = 1;
			t = 0;
		}
	}
	// 5. 남아있는 마지막 값 저장
	if (k != 1)
		res.push_back(t);
	// 6. 배열 역순 출력
	for (auto it = res.rbegin(); it != res.rend(); it++)
		cout << *it;
}