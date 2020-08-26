// 간단한 DFS 문제
// 순열 구하기

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> s; // 출력 숫자 저장
int f[10]; // 방문 여부 체크

void func(int x)
{
	// 순열 개수만큼의 깊이에 도달하면
	if (x == M)
	{
		// 저장한 순열 출력
		for (int i = 0; i < s.size(); i++)
			cout << s[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (f[i]) continue; // 이미 체크 되었다면 순열 불가능
		f[i] = 1; // 숫자 체크
		s.push_back(i); // 순열에 집어넣기
		func(x + 1); // 깊이 증가
		s.pop_back(); // 순열에서 빼기
		f[i] = 0; // 체크 초기화
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin >> N >> M;
	func(0); // 깊이 0부터 시작
}