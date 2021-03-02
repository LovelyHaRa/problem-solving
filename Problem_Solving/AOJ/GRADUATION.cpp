#include<iostream>
#include<vector>
#include<intrin.h>

using namespace std;

const int INF = 987654321;
int n, k, m, l;
vector<int> prerequisite; // 선수과목 집합
vector<int> classes; // 학기 개설과목 집합
vector<vector<int>> cache; // 캐시

// 켜진 비트수 반환
int bitCount(int n) { return __popcnt(n); /* __builtin_popcount(n); // g++ */ } 
int min(int a, int b) { return a < b ? a : b; }

// 이번학기가 smemster이고 지금까지 들은 과목의 집합이 taken일 때
// k개 이상 과목을 들을려면 몇학기나 더 있어야 하는가
int graduate(int semester, int taken)
{
	// 기저 사례: 이미 k개 이상 들은 경우
	if (bitCount(taken) >= k) return 0;
	// 기저 사례: m학기가 전부 지난 경우(IMPOSSIBLE)
	if (semester == m) return INF; // INF값 반환
	// 메모이제이션
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF; // 초기 세팅
	// 이번학기에 들을 수 있는 과목 중 아직 듣지 않은 과목을 찾는다.
	int canTake = (classes[semester] & ~taken); // semester와  taken의 차집합을 구한다.
	// 선수 과목을 다 듣지 않은 과목을 베제한다
	for (int i = 0; i < n; i++)
		// 현재 과목을 안들었는데 선수과목을 모두 듣지 않았으면
		if ((canTake&(1 << i)) && (taken&prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i); // 원소 삭제
	// canTake의 모든 부분집합 순회
	for (int take = canTake; take; take = ((take - 1) & canTake))
	{
		if (bitCount(take) > l) continue; // 학기당 l개 이하만 들을 수 있다
		// 해당 부분집합의 과목들을 수강 했을 때 최솟값 갱신
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	// 이번학기 휴학
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> m >> l;
		prerequisite.resize(n);
		for (int i = 0; i < n; i++)
		{
			int r;
			cin >> r;
			for (int j = 0; j < r; j++)
			{
				int ri;
				cin >> ri;
				prerequisite[i] |= (1 << ri);
			}
		}
		classes.resize(m);
		for (int i = 0; i < m; i++)
		{
			int c;
			cin >> c;
			for (int j = 0; j < c; j++)
			{
				int ci;
				cin >> ci;
				classes[i] |= (1 << ci);
			}
		}
		cache.resize(n, vector<int>(1 << n, -1));
		int res = graduate(0, 0);
		if (res == INF) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
		prerequisite.clear();
		classes.clear();
		cache.clear();
	}
}
