#include <string>
#include <vector>

using namespace std;

// 카운트 구하기
int getCount(string start, string end) {
	// 시간 계산
	int hour = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
	// 분 계산
	int s_min = stoi(start.substr(3, 2)), e_min = stoi(end.substr(3, 2));
	int min, lower = 0;
	if (s_min > e_min) {
		min = 60 - s_min + e_min;
		lower = 1; // 자리 내림
	}
	else {
		min = e_min - s_min;
	}
	// 분으로 환산 후 리턴
	return (hour - lower) * 60 + min;
}
string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	vector<pair<string, int>> info; // 제목, 카운트 페어 배열
	for (int i = 0; i < musicinfos.size(); i++) {
		// 1. 시간 추출
		string start = musicinfos[i].substr(0, 5);
		string end = musicinfos[i].substr(6, 5);
		int j = 12; // 제목 시작점
		string name, melody; // 제목, 멜로디
		string t; // 임시 문자열
		// 2. 제목 추출
		while (1) {
			if (musicinfos[i][j] == ',') {
				name = t;
				break;
			}
			else {
				t += musicinfos[i][j++];
			}
		}
		// 3. 멜로디 추출
		melody = musicinfos[i].substr(j + 1);
		// 4. 카운팅 구하기(시간차)
		int count = getCount(start, end);
		int c = count; // 카운트 복사(저장할 때 사용)
		t = ""; // 재생된 멜로디
		// 5. 재생된 멜로디 문자열 구하기
		j = 0;
		while (count > 0) {
			if (j == melody.size()) j = 0; // j가 배열 범위를 벗어나면 초기화
			// 다음 참조값이 # 이면 소문자로 바꿔서 저장
			if (j + 1 < melody.size() && melody[j + 1] == '#') {
				t += melody[j] + 32; // 소문자로 바꾸기
				j += 2; // # 뛰어넘기
			}
			// 그렇지 않으면 변환 없이 저장
			else {
				t += melody[j++];
			}
			count--;
		}
		// 6. 기억한 멜로디도 #을 소문자로 바꿔서 저장
		string mm;
		j = 0;
		while (j < m.size()) {
			// 다음 참조값이 # 이면 소문자로 바꿔서 저장
			if (j + 1 < m.size() && m[j + 1] == '#') {
				mm += m[j] + 32; // 소문자로 바꾸기
				j += 2; // # 뛰어넘기
			}
			// 그렇지 않으면 변환 없이 저장
			else {
				mm += m[j++];
			}
		}
		// 7. 문자열 찾기
		auto n = t.find(mm);
		// 8 발견하면 info 배열에 페어 저장
		if (n == string::npos) continue;
		info.push_back({ name, c });
	}
	int max = -1;
	// 9. 카운트가 최대값인 info 값 저장
	for (int i = 0; i < info.size(); i++) {
		if (max < info[i].second) {
			max = info[i].second;
			answer = info[i].first;
		}
	}
	return answer;
}
