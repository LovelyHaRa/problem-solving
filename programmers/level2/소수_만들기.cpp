#include <vector>
#include <iostream>

using namespace std;

// 소수 판별 함수
bool isPrime(int k) {
	if (k == 1) return false;
	for (int i = 2; i*i <= k; i++) {
		if (!(k%i)) return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;
	// 3개의 수 선택을 삼중 반복문으로 선택
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if (isPrime(nums[i] + nums[j] + nums[k])) answer++;
			}
		}
	}
	return answer;
}
