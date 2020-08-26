#include <string>
#include <vector>

using namespace std;

// 해당 로그 라인의 끝나는 시간(ms), 처리시간(ms)을 변환하여 반환
pair<int, int> getTime(string line) {
	// 로그 시간(끝나는 시간) string 추출
	string hh = line.substr(11, 2);
	string mm = line.substr(14, 2);
	string ss = line.substr(17, 6);
	ss.erase(ss.begin() + 2);
	// 로그 시간 변환
	int h = stoi(hh) * 60 * 60 * 1000;
	int m = stoi(mm) * 60 * 1000;
	int s = stoi(ss);
	// 끝나는 시간 추출
	string p = line.substr(24);
	p.pop_back();
	// 끝나는 시간 변환
	int ptime = stod(p) * 1000;
	// 리턴
	return make_pair(h + m + s, ptime);
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> start, end; // 시작 시간, 끝나는 시간 배열
	// 로그 탐색
	for (int i = 0; i < lines.size(); i++) {
		// 시간 변환
		pair<int, int> t = getTime(lines[i]);
		// 시작 시간 구하기
		int startTime = t.first - t.second + 1;
		// 시작 시간이 어제라면 0으로 만들기
		if (startTime < 0) startTime = 0;
		// 배열에 삽입
		start.push_back(startTime);
		end.push_back(t.first);
	}
	// 각 로그 별로 끝나는 시간을 기준으로 1초 동안 처리된 양을 구한다
	for (int i = 0; i < lines.size(); i++) {
		int cnt = 1; // 해당 시간 처리량
		int effectTime = end[i] + 999; // 시간 범위
		// 오늘을 넘기면 당일 마지막 초 저장
		if (effectTime > 60 * 60 * 24 * 1000) effectTime = 60 * 60 * 24 * 1000;
		// 현재 로그 기준 부터 로그 끝까지 탐색
		for (int j = i + 1; j < lines.size(); j++) {
			// 시작 시간이 시간 범위 내에 있으면 처리량 증가
			if (start[j] <= effectTime) {
				cnt++;
			}
		}
		// 처리량 최대값 갱신
		answer = answer < cnt ? cnt : answer;
	}
	return answer;
}