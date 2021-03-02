#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<long long> num; // 숫자 추출 배열
vector<char> op; // 연산자 추출 배열

// 수식을 숫자와 연산자로 분리
void convert(string exp) {
	int n = 0;
	for (int i = 0; i < exp.size(); i++) {
		// 숫자
		if (exp[i] >= '0' && exp[i] <= '9') {
			n *= 10;
			n += (exp[i] - '0');
		}
		// 연산자
		else {
			num.push_back(n); // 숫자 저장
			n = 0;
			op.push_back(exp[i]); // 연산자 저장
		}
	}
	num.push_back(n); // 마지막 수 저장
}

char oper[] = { '+','-','*' }; // 연산자
bool check[3]; // oper 탐색 여부 확인
vector<char> selected; // oper에서 선택된 연산자 우선순위
long long answer = 0; // 상금의 최댓값(리턴 값)

// a, b를 op로 계산
long long calc(long long a, long long b, char op) {
	switch (op) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

// 연산자 우선순위가 dfs에 의해 결정되었을 때, 주어진 수식을 계산
void getScore() {
	// 계산을 위해 숫자, 연산자 배열을 복사
	vector<long long> cnum = num;
	vector<char> cop = op;
	// i: 연산자 우선순위, j: 수식에 들어있는 연산자 순서
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cop.size(); j++) {
			// 해당 연산자가 우선순위를 만족하면
			if (selected[i] == cop[j]) {
				cnum[j] = calc(cnum[j], cnum[j + 1], cop[j]); // 계산 후 첫번째 피연산자에 저장
				cnum.erase(cnum.begin() + j + 1); // 두번째 피연산자 제거
				cop.erase(cop.begin() + j); // 계산된 연산자 제거
				j--; // 전체 길이가 1 줄었으므로 j도 감소 시킴
			}
		}
	}
	answer = max(answer, abs(cnum[0])); // 절댓값 취한 후 최댓값 갱신
}

// 모든 연산자 우선순위를 탐색하기 위한 dfs
void dfs(int cnt) {
	// 연산자 우선순위가 결정되었으면
	if (cnt == 3) {
		getScore(); // 수식 계산
	}
	// 연산자 탐색
	for (int i = 0; i < 3; i++) {
		// 체크 안되어있으면
		if (!check[i]) {
			check[i] = 1; // 체크
			selected.push_back(oper[i]); // 우선순위 배열 갱신
			dfs(cnt + 1);
			// 원상 복구
			check[i] = 0;
			selected.pop_back();
		}
	}
}

long long solution(string expression) {
	convert(expression); // 수식 컨버트
	dfs(0); // dfs 탐색
	return answer;
}
