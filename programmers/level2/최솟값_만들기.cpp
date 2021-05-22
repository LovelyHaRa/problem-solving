#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	int n = A.size();
	// 누적 최솟값은 매 탐색마다
	// 한쪽 배열에서 최댓값, 다른 한쪽 배열에서 최소값을 꺼내어
	// 곱한 값을 더하면 된다.

	// 1. A는 내림차순, B는 오름차순 정렬(바뀌어도 무관)
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end());
	// 2. 위치가 같은 원소를 곱한 값을 더하면 정답
	for (int i = 0; i < n; i++) {
		answer += A[i] * B[i];

	return answer;
}
