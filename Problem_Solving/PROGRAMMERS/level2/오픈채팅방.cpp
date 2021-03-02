#include <string>
#include <vector>
#include<iostream>
#include <cstring>
#include<map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	// 1. id <-> 사용자 이름 매칭
	for (int i = 0; i < record.size(); i++) {
		// char* 형변환
		char t[30];
		strcpy(t, record[i].c_str());
		// 문자열 토큰 분리
		char *token = strtok(t, " ");
		char cmd[3][20];
		int j = 0;
		while (token != NULL) {
			strcpy(cmd[j++], token);
			token = strtok(NULL, " ");
		}
		// key value 갱신
		if (!strcmp(cmd[0], "Enter") || !strcmp(cmd[0], "Change")) {
			m[cmd[1]] = cmd[2];
		}
	}
	// 2. message 출력
	for (int i = 0; i < record.size(); i++) {
		// char* 형변환
		char t[30];
		strcpy(t, record[i].c_str());
		// 문자열 토큰 분리
		char *token = strtok(t, " ");
		char cmd[3][20];
		int j = 0;
		while (token != NULL) {
			strcpy(cmd[j++], token);
			token = strtok(NULL, " ");
		}
		// 커맨드에 따른 메시지 저장
		if (!strcmp(cmd[0], "Enter")) {
			string res(m[cmd[1]] + "님이 들어왔습니다.");
			answer.push_back(res);
		}
		else if (!strcmp(cmd[0], "Leave")) {
			string res(m[cmd[1]] + "님이 나갔습니다.");
			answer.push_back(res);
		}
	}
	return answer;
}
