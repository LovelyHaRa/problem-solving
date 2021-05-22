#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector <vector<int>> bino(201, vector<int>(201)); // 이항계수 저장
const int M = 1000000000 + 100; // 오버플로 방지 
int min(int a, int b) { return a < b ? a : b; }

// 이항계수 구하기
void calcBino()
{
	for (int i = 0; i <= 200; i++)
	{
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

// O(nm)
int skip;
void generate(int n, int m, string s)
{
	if (skip < 0) return; // 문자열을 출력한 뒤이므로 바로 종료
	// 기저사례: m==n==0
	if (n == 0 && m == 0)
	{
		if (skip == 0)	cout << s << '\n'; // k번째이면 출력
		skip--;
		return;
	}
	// k가 (n+m,n)보다 크면 해당 이항계수만큼 무시
	if (bino[n + m][n] <= skip)
	{
		skip -= bino[n + m][n];
		return;
	}
	// 모스부호 붙이기
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

// O(n+m)
string kth(int n, int m, int skip)
{
	if (n == 0) return string(m, 'o'); // n이 0이면 나머지는 o일수 밖에 없다
	// 반으로 나눠 생각하기
	if (n > 0 && skip < bino[n + m - 1][n - 1])
		return "-" + kth(n - 1, m, skip);
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main(void)
{
	calcBino();
	int c;
	cin >> c;
	while (c--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		//skip = k - 1;
		//generate(n, m, "");
		cout << kth(n, m, k - 1)<<'\n';
	}
}
