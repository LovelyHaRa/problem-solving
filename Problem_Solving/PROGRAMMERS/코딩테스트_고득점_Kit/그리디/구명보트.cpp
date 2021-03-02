#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	// 1. 오름차순 정렬
	sort(people.begin(), people.end());
	int min = 0, max = people.size() - 1;
	// 2. 양 끝에서 시작, 같아질때까지 반복
	while (min < max) {
		// 3. 각 위치에 몸무게를 합해서 태울 수 있으면 왼쪽 값 증가
		if (people[min] + people[max] <= limit) {
			min++;
		}
		// 4. 그렇지 않으면 어차피 오른쪽 값은 혼자 타는 방법 외엔 없으므로 보트수 추가
		answer++;
		// 5. 모든 경우에 대해 오른쪽 값 감소
		max--;
	}
	// 6. 짝수 명이면 교차(차이가 -1), 홀수 명이면 인덱스가 같아짐
	// 홀수 명일 때 비교 못한 한명의 보트를 추가
	if (min == max)
		answer++;
	return answer;
}
