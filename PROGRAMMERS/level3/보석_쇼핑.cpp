#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 비교 함수
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	// 2. 시작 번호 오름차순
	if (p1.second - p1.first == p2.second - p2.first)
		return p1.first < p2.first;
	// 1. 범위 길이 오름차순
	return p1.second - p1.first < p2.second - p2.first;
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	set<string> gemset; // 보석 종류 집합
	// 1. 보석 종류 저장
	for (string gem : gems) {
		gemset.insert(gem);
	}
	unordered_map<string, int> display; // 진열대의 번호, 시작지점을 map으로 저장
	vector<pair<int, int>> range; // 쇼핑할 수 있는 진열대 범위(시작, 끝)
	int n = gems.size();
	// 2. 진열대 탐색
	for (int i = 0; i < n; i++) {
		display[gems[i]] = i; // 진열대 map에 저장
		// 시작 진열대 번호
		int start_dp = n - 1; 
		// map에 보석 종류가 모두 저장되었다면 쇼핑 가능
		if (display.size() == gemset.size()) {
			// 시작 진열대 번호 구하기
			for (auto it = display.begin(); it != display.end(); it++) {
				start_dp = start_dp > it->second ? it->second : start_dp;
			}
			// 범위 저장
			range.push_back(make_pair(start_dp, i));
		}
	}
	// 3. 범위 정렬
	sort(range.begin(), range.end(), compare);
	// 4. 리턴
	answer.push_back(range[0].first + 1);
	answer.push_back(range[0].second + 1);
	return answer;
}
