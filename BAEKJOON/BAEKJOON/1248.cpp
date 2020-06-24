#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<char>> c; // 합의 종류 테이블
vector<int> ans; // 정답 배열
vector<int> psum; // 정답의 부분합 배열
bool success = false; // 정답을 찾았을 경우 함수를 끝내기 위한 플래그

// start ~ end 구간의 합의 부호가 c랑 일치하는지 확인한다
bool check(int start, int end, char c)
{
	int sum = start == 0 ? psum[end] : psum[end] - psum[start - 1];
	// c의 부호에 따른 처리
	switch (c)
	{
	case '-':
		return sum < 0 ? true : false;
	case '0':
		return sum == 0 ? true : false;
	case '+':
		return sum > 0 ? true : false;
	}
}

// cnt개의 숫자를 탐색했을 때 배열이 정답 조건을 만족하는지 판단한다
void process(int cnt)
{	
	// 합의 종류 테이블과 조건이 일치하지 않으면 반환시킨다
	for (int i = 0; i < cnt; i++)
		for (int j = i; j < cnt; j++)
			if (!check(i, j, c[i][j])) return;
	// 리턴되지 않았으면 지금까지 추가된 숫자들이 조건을 만족함을 의미
	// 기저 사례: cnt==n
	if (cnt == n)
	{
		// 출력한다
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		success = true;
		return;
	}
	// 다음 숫자 추가
	// 0일 경우 탐색
	if (c[cnt][cnt] == '0')
	{
		ans[cnt] = 0; // 0 추가
		// 부분합 추가
		cnt == 0 ? psum[cnt] = ans[cnt] : psum[cnt] = psum[cnt - 1] + ans[cnt];
		// 다음 지점 탐색
		process(cnt + 1);
		// 성공했을 경우 빠른 종료
		if (success) return;
	}
	// 1~10일 경우 탐색
	for (int i = 1; i <= 10; i++)
	{
		ans[cnt] = c[cnt][cnt] == '-' ? -i : i; // 숫자 추가
		// 부분합 추가
		cnt == 0 ? psum[cnt] = ans[cnt] : psum[cnt] = psum[cnt - 1] + ans[cnt];
		// 다음 지점 탐색
		process(cnt + 1);
		// 성공했을 경우 빠른 종료
		if (success) return;
	}
}

int main(void)
{
	cin >> n;
	c.resize(n, vector<char>(n));
	ans.resize(n);
	psum.resize(n);
	// i~j 구간의 합의 종류를 입력받는다
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> c[i][j];
	process(0);
}