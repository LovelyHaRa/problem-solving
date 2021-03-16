#include <cstdio>
#include <vector>

using namespace std;

vector<int> arr;

// 전위 순회 결과의 첫번째 인덱스의 값은 root 노드이다
// 두번째 인덱스부터 첫번째 인덱스보다 큰값의 인덱스 전까지 왼쪽 서브트리다
// 나머지는 오른쪽 서브트리이다
void postOrder(int start, int end)
{
	// 기저 사례: 범위를 벗어나면 리턴
	if (start >= end) return;
	int idx = start;
	// 루트 노드보다 큰 값의 인덱스를 구한다
	while (++idx < end && arr[idx] < arr[start]);

	postOrder(start + 1, idx); // 왼쪽 서브트리 재귀 탐색
	postOrder(idx, end); // 오른쪽 서브트래 재귀 탐색
	printf("%d\n", arr[start]); // 루트노드 출력
}
int main(void)
{
	int n;

	while (scanf("%d", &n) > 0) arr.push_back(n);
	postOrder(0, arr.size());
}