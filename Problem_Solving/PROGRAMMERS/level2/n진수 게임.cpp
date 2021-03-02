#include <string>
#include <vector>
#include<iostream>

using namespace std;

// 진법 변환 후 문자열로 반환해주는 함수
string makeNum(int x, int n) {
	// 16진법까지의 문자를 저장
	char num[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	string res;
	// 진법 변환
	while (x / n > 0) {
		res = num[x%n] + res;
		x /= n;
	}
	// 몫이 0일때(마지막 수) 붙이기
	res = num[x%n] + res;
	return res;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string arr; // 게임 배열
	// 최소 크기는 t*m
	for (int i = 0; i < t*m; i++) {
		// 현재 숫자를 진법 변환 후 문자열로 이어붙임
		arr += makeNum(i, n);
	}
	// 인덱스기반(p-1)부터 자신의 차례에 말해야 하는 수를 이어붙임
	for (int i = 0, q = p - 1; i < t; i++, q += m) {
		answer += arr[q];
	}
	return answer;
}