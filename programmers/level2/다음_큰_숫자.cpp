#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int k = n;
	int count = 0;
	// 1. n의 1의 개수를 구한다.
	while (k) {
		k % 2 ? count++ : count;
		k = k >> 1; // = k/2;
	}
	// 2. n+1부터 1씩 증가시키면서 탐색
	k = n + 1;
	while (1) {
		int tcount = 0;
		int tk = k;
		// 3. 현재 값의 1의 개수를 구한다.
		while (tk) {
			tk % 2 ? tcount++ : tcount;
			tk = tk >> 1;
		}
		// 4. n의 1의 개수와 같으면 리턴
		if (count == tcount) return k;
		k++;
	}
}
