#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	// 최고의 집합의 조건
	// 1. 합이 S가 되는 수의 집합들 중 곱의 최대값은 집합의 모든 원소값들의 절대값이 최소가 되어야함
	// 2. 1의 조건을 만족하는 집합은 중복된 수가 최대한 많은 집합임(절대값 0)
	// 3. S를 n개의 수로 표현할려면 (S/n) n-1개, (s/n+s%n) 1개로 표현 가능
	// 4. 하지만 1,2의 조건을 만족하려면 (s/n+1) s%n개, s/n이 n-s%n 개 있어야한다
	vector<int> answer;
	// 최고의 집합이 존재하지 않는 경우
	if (n > s) {
		answer.resize(1, -1);
		return answer;
	}
	answer.resize(n);
	int div = s / n; // 몫
	int mod = s % n; // 나머지
	// 뒤에서 부터 저장(오름차순 배열 리턴)
	for (int i = n - 1; i >= 0; i--)
	{
		int p;
		p = (mod-- > 0) ? 1 : 0; // 1을 더할지 말지 결졍
		answer[i] = div + p;
	}
	return answer;
}
