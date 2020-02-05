#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int MAX = 1e7;
int prime[MAX];

// 에라토스테네스의 체를 이용하여 소수 테이블 생성
void setPrime()
{
	prime[0] = prime[1] = -1;
	for (int i = 2; i <= MAX; i++)
		prime[i] = i;
	for (int i = 2; i*i <= MAX; i++) {
		if (prime[i] == i)
		{
			for (int j = i * i; j <= MAX; j += i) {
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	vector<int> num; // 숫자 단위로 저장
	map<int, bool> visited; // 중복 된 수를 체크하기 위해
	// 1. 소수테이블 생성
	// 2. 숫자 단위로 저장
	// 3. 1부터 숫자 자리 개수까지 완전 탐색
	// 4. 순열 생성
	// 5. 현재 자리 수만큼 숫자 합치기
	// 6. 중복 여부 검사
	// 7. 소수 검사
	// 1
	setPrime();
	// 2
	for (int i = 0; i < numbers.length(); i++)
		num.push_back(numbers[i] - '0');
	// 3
	for (int i = 1; i <= num.size(); i++)
	{
		// 4
		sort(num.begin(), num.end());
		do
		{
			// 5
			string s;
			for (int j = 0; j < i; j++) {
				// 첫째자리가 0일 수는 없다
				if (s.empty() && num[j] == 0)
					continue;
				s += num[j] + '0';
			}
			// 숫자가 저장되지 않았다면(0이라면);
			if (s.empty())
				continue;
			// 숫자 변환
			int k = stoi(s);
			// 6
			if (visited.count(k))
				continue;

			visited[k] = true; // 최초 탐색된 수, 중복 체크
			// 7
			if (prime[k] == k)
				answer++;
		} while (next_permutation(num.begin(), num.end())); // 4
	}
	return answer;
}