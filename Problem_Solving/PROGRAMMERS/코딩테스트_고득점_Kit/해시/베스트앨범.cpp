#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

// pair 비교함수 작성법
template<template <typename> class P = less>
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const pair<T1, T2>&left, const pair<T1, T2>&right) {
		// 비교 값이 같으면 인덱스가 낮은 값으로 정렬
		if (left.second == right.second)
			return less<T1>()(left.first, right.first);
		return P<T2>()(left.second, right.second);
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	// 1. 장르별 전체 재생 수를 map으로 저장
	map<string, int> total_play;
	for (int i = 0; i < plays.size(); i++) {
		total_play[genres[i]] += plays[i];
	}
	// 2. 내림차순 정렬 (map은 정렬이 안되기 때문에 vector 배열로 옮긴 뒤 정렬)
	vector<pair<string, int>> total(total_play.begin(), total_play.end());
	sort(total.begin(), total.end(), compare_pair_second<greater>());
	// 3. 정렬 후 탐색
	for (int i = 0; i < total.size(); i++) {
		// 4. 현재 장르 값 추출
		vector<pair<int, int>> genre;
		for (int j = 0; j < plays.size(); j++) {
			if (genres[j] == total[i].first) {
				genre.push_back({ j, plays[j] });
			}
		}
		// 5. 현재 장르 재생 수 내림차순 정렬
		sort(genre.begin(), genre.end(), compare_pair_second<greater>());
		// 6. 최대 2개 뽑아서 인덱스만 삽입
		for (int j = 0; j < genre.size() && j < 2; j++) {
			answer.push_back(genre[j].first);
		}
	}
	return answer;

}
