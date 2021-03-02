#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 문자열 만들기
//void curve(const string& seed, int generations)
//{
//	if (generations == 0)
//	{
//		cout << seed;
//		return;
//	}
//	for (int i = 0; i < seed.size(); i++)
//	{
//		if (seed[i] == 'X')
//			curve("X+YF", generations - 1);
//		else if (seed[i] == 'Y')
//			curve("FX-Y", generations - 1);
//		else
//			cout << seed[i];
//	}
//}

const int MAX = 1000000000 + 1;
vector<int> length(51); // N세대의 드래곤커브 길이
int min(int a, int b) { return a < b ? a : b; }

// N세대의 드래곤커브의 길이를 미리 구하기
void precalc()
{
	length[0] = 1;
	for (int i = 1; i <= 50; i++)
		length[i] = min(MAX, 2 + 2 * length[i - 1]);
}
// X, Y일 때 치환할 문자열
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

// k번째 드래곤커브 문자열 출력
char expand(const string& dragonCurve, int generations, int skip)
{
	// 기저사례: 0세대일경우
	if (generations == 0)
		return dragonCurve[skip];
	for (int i = 0; i < dragonCurve.size(); i++)
	{
		// 문자열이 확장되는 경우
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
		{
			if (skip >= length[generations])
				skip -= length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else if (dragonCurve[i] == 'Y')
				return expand(EXPAND_Y, generations - 1, skip);
		}
		// 확장되진 않지만 건너뛰어야 할 경우
		else if (skip > 0) --skip;
		// 답을 찾은 경우
		else return dragonCurve[i];
	}	
}

int main(void)
{
	// 길이를 미리 구함
	precalc();
	int c;
	cin >> c;
	while (c--)
	{
		int n, p, l;
		cin >> n >> p >> l;
		// k번째 드래곤커브 문자열 출력(인덱스 때문에 -1) (p-1<=k<p+l-1) 
		for (int i = p - 1; i < p + l - 1; i++)
			cout << expand("FX", n, i);
		cout << '\n';
	}
}