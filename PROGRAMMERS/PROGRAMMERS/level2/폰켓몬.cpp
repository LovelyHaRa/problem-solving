#include <vector>
#include <map>

using namespace std;

int min(int a, int b) {
	return a < b ? a : b;
}

int solution(vector<int> nums)
{
	int answer = 0;
	map<int, int> m;
	// 종류만 저장
	for (int i = 0; i < nums.size(); i++) {
		m[nums[i]]++;
	}
	// 종류의 수, 전체 개수/2 중 최솟값 리턴
	return min(m.size(), nums.size() / 2);
}