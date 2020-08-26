#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0;
	// 0부터 시작하는게 아닌 N부터 시작하는 것으로 생각
	while (n > 2) {
		// 2로 나누어 떨어지지 않으면 1칸 이동
		if (n % 2) {
			ans++; // 건전지 1 소비
			n--; // 1칸 이동
		}
		// 나누어 떨어지면 순간이동
		else {
			// 순간이동은 비용 소비 없음
			n /= 2;
			
		}
	}
	// 2는 무조건 건전지 1 소비(1점프, 1*1순간이동)
	return ans + 1;
}