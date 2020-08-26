#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 좌표평면 상 점 표현
class Point
{
public:
	int x, y;
};

// 비교 구조체
struct compare
{
	bool comp_in_x; // x좌표 기준 정렬 여부
	compare(bool b) : comp_in_x(b) {};
	// 연산자 오버로딩
	bool operator()(Point &p, Point &q) {
		return (this->comp_in_x ? p.x < q.x : p.y < q.y);
	}
};

// 두 점 사이의 거리
int dist(Point &p, Point &q)
{
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

// 두 점사이의 거리의 최솟값을 구하는 함수
int closest_pair(vector<Point>::iterator it, int n)
{
	// n = 3 까지는 단순 비교 가능
	if (n == 2) return dist(it[0], it[1]);
	if (n == 3) return min({ dist(it[0], it[1]), dist(it[1], it[2]), dist(it[0], it[2]) });

	// x좌표를 기준으로 중앙점에 수직으로 선을 하나 생성
	int line = (it[n / 2 - 1].x + it[n / 2].x) / 2;
	// 선을 기준으로 좌 우로 분할 정복 하여 최솟값 추출
	int d = min(closest_pair(it, n / 2), closest_pair(it + n / 2, n - n / 2));

	// 선을 관통하는 두 점 사이의 직선을 저장
	vector<Point> mid;
	mid.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int t = line - it[i].x;
		// 라인에서 x 좌표까지의 거리가 d 이상이면 절대로 최소값이 될 수 없으므로 버림
		if (t*t < d) mid.push_back(it[i]);
	}
	
	// 저장한 점을 y축 기준으로 정렬
	sort(mid.begin(), mid.end(), compare(false));

	// 가장 밑에 점부터 탐색
	int mid_sz = mid.size();
	for (int i = 0; i < mid_sz - 1; i++)
	{
		// 거리가 d 이상인 점들은 절대로 최소값이 될 수 없으므로 이후의 점들은 탐색 중단
		for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y)*(mid[j].y - mid[i].y) < d; j++)
			d = min(d, dist(mid[i], mid[j]));
	}

	return d;
}

int main(void)
{
	int n;
	cin >> n;

	vector<Point> points(n);
	for (auto i = points.begin(); i != points.end(); i++)
		cin >> i->x >> i->y;

	// x좌표 기준으로 정렬
	sort(points.begin(), points.end(), compare(true));

	// 거리의 최솟값 출력
	cout << closest_pair(points.begin(), n) << '\n';
}