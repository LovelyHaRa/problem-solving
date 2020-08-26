#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<double>> cache;

// 날짜, 기어오른 합
double climb(int days, int climbed)
{
	// 기저사례: m일까지 도달했을 때
	if (days == m) return climbed >= n ? 1.0 : 0; // 기어오른 합이 n보다 크면 성공
	// 메모이제이션
	double& ret = cache[days][climbed];
	if (ret != -1) return ret;
	// 확률을 바로 저장
	return ret = 0.25*climb(days + 1, climbed + 1) + 0.75*climb(days + 1, climbed + 2);
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		cache.resize(n, vector<double>(n * 2 + 1, -1));
		cout.precision(10); // 10자리까지 출력
		cout << climb(0, 0) << endl;		
		cache.clear();
	}
}