#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int INF = 1987654321;
string N; // 입력 문자열
vector<int> cache; // 메모이제이션 캐싱

int min(int a, int b) { return a < b ? a : b; }
int abs(int a, int b) { return a > b ? a - b : b - a; }

int classify(int a, int b)
{
	// 부분 수열 저장
	string M = N.substr(a, b - a + 1);
	// 모든 숫자가 같을 때: 1
	if (M == string(M.size(), M[0])) return 1;
	// 등차수열 확인
	bool progressive = true;
	for (int i = 1; i < M.size() - 1; i++)
	{
		// 등차수열 조건
		if (M[i + 1] - M[i] != M[1] - M[0])
		{
			progressive = false;
			break;
		}
	}
	// 공차가 1인 등차수열: 2
	if (progressive && abs(M[1] - M[0]) == 1) return 2;
	// 반복 숫자 확인
	int alternating = true;
	for (int i = 2; i < M.size(); i++)
	{
		// 두개의 숫자가 번갈아 가면서 나타나는지 확인
		if (M[i] != M[i % 2])
		{
			alternating = false;
			break;
		}
	}
	// 번갈아 가면서 나타나면: 4
	if (alternating) return 4;
	// 등차수열이면: 5
	if (progressive) return 5;
	// 그 외의 경우: 10
	return 10;
}

int memorize(int begin)
{
	// 기저 사례: begin이 끝에 도달했을 때
	if (begin == N.size()) return 0;
	// 메모이제이션
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF; // 최솟값 저장을 위한 초기화
	// 3~5글자 끊어 쓰기
	for (int i = 3; i <= 5; i++)
	{
		// (i조각 뺴고 나머지 수열에 대한 최적해 + 길이 i인 조각의 난이도)들 중 최소값 저장
		if (begin + i <= N.size())
			ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> N;
		cache.resize(N.size() + 1, -1);
		cout << memorize(0) << '\n';
		cache.clear();
	}
}