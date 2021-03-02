#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	// linked list 로 캐시 구현
	list<string> l;
	map<string, list<string>::iterator> m;
	// 1. 캐시 사이즈가 0 이면 캐시 저장 불가능 이므로 사이즈*5 리턴
	if (!cacheSize) { return cities.size() * 5; }
	// 2. cities 탐색
	for (int i = 0; i < cities.size(); i++) {
		// 3. 현재 cities uppercase
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), (int(*)(int))toupper);
		// 4. 캐시 miss 시
		if (m.find(cities[i]) == m.end()) {
			// 4-1. 캐시가 꽉 차면
			if (cacheSize == l.size()) {
				// 4-2. 리스트 마지막 원소를 제거
				string last = l.back();
				l.pop_back();
				m.erase(last);
			}
			// 시간 추가
			answer += 5;
		}
		// 5. 캐시 적중 시
		else {
			// 5-1. 리스트에서 해당 캐시값 삭제 (LRU 갱신을 위해)
			l.erase(m[cities[i]]);
			// 시간 추가
			answer += 1;
		}
		// 6. 리스트 왼쪽에 현재 값 추가 (캐시 미스, 적중 공통적으로 동작)
		l.push_front(cities[i]);
		// iterator 갱신
		m[cities[i]] = l.begin();
	}
	return answer;
}