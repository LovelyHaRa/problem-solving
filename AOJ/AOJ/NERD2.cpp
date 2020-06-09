#include<iostream>
#include<map>

using namespace std;

map<int, int> coords;

// (x, y)가 기존 점들에 의해 지배당하는지 확인
bool isDominated(int x, int y)
{
	// 탐색한다
	map<int, int>::iterator it = coords.lower_bound(x);
	// 없으면 false
	if (it == coords.end()) return false;
	// 있다면 y 보다 커야 지배를 안당한다(찾은 점은 y보다 왼쪽에 있다)
	return y < it->second;
}

// (x, y)에 의해 지배당하는 점들을 제거한다
void removeDominated(int x, int y)
{
	// 현재 점 위치 찾기
	map<int, int>::iterator it = coords.lower_bound(x);
	// 현재 점보다 직은 점이 없으면 아무 일도 안함
	if (it == coords.begin()) return;
	it--; // 이터레이터 감소
	// y값보다 큰 점이 나올때 까지 반복
	while (1)
	{
		// 중단 조건: 현재 이터레이터가 y값 이상일 경우
		if (it->second > y) break;
		// 중단 조건: 현재 이터레이터가 가장 왼쪽 점일 경우
		if (it == coords.begin())
		{
			// 현재 점을 삭제
			coords.erase(it);
			break;
		}
		// 이전 점으로 이터레이터를 하나 옮겨 놓고 it를 지운다
		else {
			map<int, int>::iterator jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

// 새 점 (x, y)가 추가되었을 때 coords를 갱신하고
// 다른 점에 지배당하지 않는 점들의 개수를 반환한다
int registered(int x, int y)
{
	// (x, y)가 이미 지배당한 경우 이 점을 그냥 버린다
	if (isDominated(x, y)) return coords.size();
	// 기존에 추가된 점들 중 지배당하는 점들을 지운다
	removeDominated(x, y);
	// 새점을 추가한다
	coords[x] = y;
	// 점들의 개수를 반환한다
	return coords.size();
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		int res = 0; // 참가자 등록 때 마다 너드의 개수를 누적
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			res += registered(x, y);
		}
		cout << res << '\n';
		coords.clear();
	}
}