#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	vector<int> minutetable; // tametable 시간들을 분 단위로 변환한 값 저장
	// 1. timetable 시간들을 분단위로 변환
	for (int i = 0; i < timetable.size(); i++) {
		int minute = 0, k = 60, j = 0;
		while (k > 0) {
			minute += stoi(timetable[i].substr(j, j + 2))*k;
			k /= 60;
			j += 3;
		}
		minutetable.push_back(minute);
	}
	// 2. 오름차순 정렬
	sort(minutetable.begin(), minutetable.end());
	// 3. 버스 탑승 시뮬레이션
	// 버스 도착 시간, timetable 인덱스, 탑승 인원 수, 도착해야되는 시간
	int bustime = 540, tableidx = 0, takecnt = m, res;
	// 셔틀 버스 순회
	for (int i = 0; i < n; i++, bustime += t) {
		takecnt = m; // 탑승 인원 수 초기화
		// 버스에 대기하는 사람 태우기
		while (takecnt-- && tableidx != minutetable.size()) {
			// 현재 버스를 못타는 사람인 경우 다음 버스를 타야된다
			if (bustime < minutetable[tableidx]) {
				break;
			}
			tableidx++; // 인덱스 증가
		}
		// 마지막 버스일 때
		if (i == n - 1) {
			// 승객을 모두 태운다면, 가장 마지막에 탄사람보다 1분 빨리와야한다
			if (takecnt < 0) res = minutetable[tableidx - 1] - 1;
			// 그렇지 않다면 버스 시간에 맞춰서 도착하면 된다
			else res = bustime;
		}
	}
	// 도착해야 되는 시간을을 시간 문자열로 변환한다
	answer += (res / 60) / 10 + '0';
	answer += (res / 60) % 10 + '0';
	answer += ':';
	answer += (res % 60) / 10 + '0';
	answer += (res % 60) % 10 + '0';
	return answer;
}
