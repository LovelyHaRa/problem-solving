#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n); // 수열
	vector<int> res(n, -1); // 오큰수수 수열
	stack<int> s; // 수열의 인덱스 스택
	s.push(0); // 초기 스택 저장
	for (int i = 0; i < n; i++)
	{
		cin >> a[i]; // 수열 저장
		if (!i) continue; // 처음 수열 값은 건너뛰기
		// 오큰수 저장: 스택이 비어있거나 top 인덱스보다 값이 작을 때 까지
		while (!s.empty() && a[s.top()] < a[i])
		{
			res[s.top()] = a[i];
			s.pop();
		}
		// 인덱스 스택에 쌓기
		s.push(i);
	}
	// 결과 출력
	for (int i = 0; i < n; i++) cout << res[i] << ' ';

}
