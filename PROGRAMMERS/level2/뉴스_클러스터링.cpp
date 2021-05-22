#include <string>
#include <vector>
#include <set>

using namespace std;

bool isAlpa(char a) {
	return a >= 'a' && a <= 'z';
}

vector<string> getUnion(string s) {
	vector<string> res;
	for (int i = 0; i < s.size() - 1; i++) {
		char a = tolower(s[i]), b = tolower(s[i + 1]);
		if (isAlpa(a) && isAlpa(b)) {
			string t;
			t += a;
			t += b;
			res.push_back(t);
		}
	}
	return res;
}

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> s1;
	vector<string> s2;

	// 1. 다중집합 만들기
	s1 = getUnion(str1);
	s2 = getUnion(str2);

	// 2. 공집합이면 1*65536 리턴
	if (s1.empty() && s2.empty()) {
		return 65536;
	}

	// 3. 교집합, 합집합 개수 구하기
	set<int> check; // 중복되는 인덱스 체크
	int count = 0; // 교집합 개수
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			// 원소가 똑같으면 교집합 개수 증가
			if (!s1[i].compare(s2[j]) && !check.count(j)) {
				count++;
				check.insert(j); // 중복 체크
				break;
			}
		}
	}
	// 합집합 개수 공식을 이용
	int ucount = s1.size() + s2.size() - count;
	// 4. 자카드 유사도 계산
	double j = count / (double)ucount * 65536;
	answer = (int)j;
	return answer;
}
