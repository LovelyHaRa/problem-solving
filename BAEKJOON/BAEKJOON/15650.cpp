// 간단한 DFS 문제
// 순열 구하기2

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> s; // 출력 숫자 저장
int f[10]; // 방문 여부 체크

void func(int x, int idx) // 달라진 점은 올림차순만 출력하기 위해 인덱스 추가
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

	for (int i = idx; i <= N; i++)
	{
		if (f[i]) continue; // 이미 체크 되었다면 순열 불가능
		f[i] = 1; // 숫자 체크
		s.push_back(i); // 순열에 집어넣기
		func(x + 1, i + 1); // 깊이 증가, 인덱스를 증가시키면서 오름차순 순열만 출력
		s.pop_back(); // 순열에서 빼기
		f[i] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	func(0, 1); // 깊이 0부터 시작
}