#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer, people;
	long long fac = 1; // n! 저장
	for (int i = 1; i <= n; i++) {
		fac *= i;
		people.push_back(i);
	}
	k--; // 인덱스화
	while (n) {
		fac /= n--; 
		answer.push_back(people[k / fac]); // k/fac의 몫이 현재 자리에 저장될 숫자의 위치
		people.erase(people.begin() + k / fac); // 숫자 제거
		k %= fac; // 나머지 갱신
	}
	return answer;
}
