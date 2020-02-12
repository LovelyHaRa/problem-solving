#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	// 1. 오름차순 정렬
	// 2. 배열과 인덱스를 비교해 처음으로 베열 값보다 인덱스가 작아질 때 인덱스를 반환한다.
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] <= i)
			return i;
	}
}