#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string to_lower(string s) {
	string res;
	for (int i = 0; i < s.size(); i++) {
		res += tolower(s[i]);
	}
	return res;
}

bool compare(vector<string> a, vector<string> b) {
	// head 추출
	string h1 = to_lower(a[0]), h2 = to_lower(b[0]); // 문자열 lowercase
	// 같으면 숫자 비교
	if (h1 == h2) {
		return stoi(a[1]) < stoi(b[1]);
	}
	// 다르면 head 비교
	else return h1 < h2;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	// 0, 1, 2 => head, number, tail
	vector<vector<string>> k(files.size(), vector<string>(3));
	// 1. 파일명 분리
	for (int i = 0; i < files.size(); i++) {
		int j = 0;
		string t;
		// head 분리
		while (j < files[i].size()) {
			// 숫자가 처음 발견되면 멈춤
			if (files[i][j] >= '0' && files[i][j] <= '9') {
				break;
			}
			t += files[i][j++]; // 문자 누적
		}
		k[i][0] = t; // head 삽입
		t = ""; // 초기화
		// number 분리
		while (j < files[i].size()) {
			// 숫자가 끝나면 멈춤
			if (files[i][j]<'0' || files[i][j]>'9') {
				break;
			}
			t += files[i][j++];
		}
		k[i][1] = t; // number 삽입
		k[i][2] = files[i].substr(j); // 나머지(tail) 삽입
	}
	// 2. 안정 정렬: 같은 값에 대해 순서가 보장되는 정렬
	stable_sort(k.begin(), k.end(), compare);
	// 3. 정렬 결과 출력
	for (int i = 0; i < k.size(); i++) {
		string t = k[i][0] + k[i][1] + k[i][2];
		answer.push_back(t);
	}
	return answer;
}

int main(void) {
	solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
}
