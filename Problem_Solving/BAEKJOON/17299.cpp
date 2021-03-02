#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n); // 수열
	vector<int> count(1000001); // 카운팅 수열
	vector<int> res(n, -1); // 오등큰수 수열
	stack<int> s; // 수열의 인덱스 스택
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // 수열 저장
		count[a[i]]++; // 카운팅
	}
	for (int i = 0; i < n; i++)
	{
		// 오등큰수 저장: 현재 위치의 카운팅 값이 스택의 카운팅 값보다 작을 때 까지 스택에서 꺼냄
		while (!s.empty() && count[a[s.top()]] < count[a[i]])
		{
			res[s.top()] = a[i]; // 결과 저장
			s.pop();
		}
		// 인덱스 스택 쌓기
		s.push(i);
	}
	// 결과 출력
	for (int i = 0; i < n; i++) cout << res[i] << ' ';

}
