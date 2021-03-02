#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
	int answer = 1; // 정답의 최소값은 반드시 1(1자리 문자열)
	int n = s.size(); // 부분 문자열 길이
	while (n > 0) {
		int i;
		// 부분 문자열 탐색
		for (i = 0; i <= s.size() - n; i++) {
			int j;
			// 펠린드롬 검사(양 사이드가 똑같으면 반복문이 끝까지 수행됨)
			for (j = 0; j < n / 2; j++) {
				if (s[i + j] != s[i + n - j - 1]) break;
			}
			// 반복문이 끝까지 수행되면 현재 n이 최댓값이므로 리턴
			if (j == n / 2) {
				return n;
			}
		}
		n--; // 짝수도 가능하므로 1씩 감소
	}
	// 최소값 반환
	return answer;
}