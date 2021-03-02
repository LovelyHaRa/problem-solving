#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

// 단일 변수 다항식 p의 계숙 ㅏ주어질 때 미분한 결과의 계수를 반환한다
vector<double> differentiate(const vector<double>& poly)
{
	vector<double> ret;
	int n = poly.size() - 1;
	for (int i = 0; i < n; i++)
		ret.push_back((n - i)*poly[i]);
	return ret;
}
// 1차 or 2차 방정식의 해를 구한다
vector<double> solveNative(const vector<double>& poly)
{
	int n = poly.size() - 1;
	vector<double> ret;
	switch (n)
	{
	case 1:
		ret.push_back(-poly[1] / poly[0]);
		break;
	case 2:
		double a = poly[0], b = poly[1], c = poly[2];
		ret.push_back((-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		ret.push_back((-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		break;
	}
	sort(ret.begin(), ret.end());
	return ret;
}
//  다항식 f(x)의 계수 poly가 주어질 때, f(x0)을 반환한다.
double evaluate(const vector<double>& poly, double x0)
{
	int n = poly.size() - 1;
	double ret = 0;
	for (int i = 0; i <= n; i++)
		ret += poly[i] * pow(x0, (n - i));
	return ret;
}
// 양 끝점
const double L = 25;
// 다항식의 근을 반환한다.
vector<double> solve(const vector<double>& poly)
{
	int n = poly.size() - 1;
	// 기저 사례: 2차 이하 다항식은 해결 가능
	if (n <= 2) return solveNative(poly);
	// 방정식을 미분해서 n-1차 방정식을 얻는다
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);
	// 이 극점들 사이를 하나하나 검사하며근이있나 확인한다.
	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);
	vector<double> ret;
	for (int i = 0; i + 1 < sols.size(); i++)
	{
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		// 부호가 같은 경우 답이 없다
		if (y1*y2 > 0) continue;
		// 불변 조건 충족
		if (y1>y2) { swap(y1, y2); swap(x1, x2); }
		// 이분법 사용
		for (int iter = 0; iter < 100; iter++)
		{
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			if (y1*my > 0)
			{
				y1 = my;
				x1 = mx;
			}
			else
			{
				y2 = my;
				x2 = mx;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	cout.precision(12);
	sort(ret.begin(), ret.end());
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<double> poly(n + 1);
		for (int i = 0; i < n + 1; i++)
			cin >> poly[i];
		vector<double> res = solve(poly);
		for (int i = 0; i < res.size(); i++)
			cout << fixed << res[i] << ' ';
		cout << '\n';
	}
}
