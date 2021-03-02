#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 최소값의 위치를 저장하는 세그먼트 트리 초기화
void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
	// 리프 노드의 경우
	if (start == end)
		tree[node] = start;
	else
	{
		// 좌,우를 따로 초기화
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		// 최솟값의 위치 저장
		if (a[tree[node * 2]] <= a[tree[node * 2 + 1]])
			tree[node] = tree[node * 2];
		else
			tree[node] = tree[node * 2 + 1];
	}
}

// 가장 높이가 낮은 사각형을 찾는 함수
int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int i, int j)
{
	// [i, j]가 [start, end]와 겹치지 않는 경우
	if (i > end || j < start)
		return -1; // 탐색을 이어나갈 필요가 없음
	// [i, j]가 [start, end]를 완전히 포함하는 경우
	if (i <= start && j >= end)
		return tree[node];
	// 위 경우가 아닌 경우 왼쪽 오른쪽 나눠서 다시 탐색
	int m1 = query(a, tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(a, tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	// 겹치지 않는 경우 제외
	if (m1 == -1)
		return m2;
	else if (m2 == -1)
		return m1;
	// 탐색 결과 중 높이가 작은 인덱스 반환
	else
		return a[m1] <= a[m2] ? m1 : m2;
}

// 최대 넓이를 구하는 함수
long long largest(vector<int> &a, vector<int> &tree, int start, int end)
{
	int n = a.size();
	// 범위 내 최소 사각형 높이를 찾음
	int m = query(a, tree, 1, 0, n - 1, start, end);
	// 넓이 = 사각형 높이 * 범위
	long long area = (long long)(end - start + 1)*(long long)a[m];
	// 해당 사각형 왼쪽 부분 탐색이 가능할 때
	if (start <= m - 1)
	{
		long long temp = largest(a, tree, start, m - 1);
		// 최댓값 갱신
		if (temp > area)
			area = temp;
	}
	// 해당 사각형 오른쪽 부분 탐색이 가능할 때
	if (end >= m + 1)
	{
		long long temp = largest(a, tree, m + 1, end);
		// 최댓값 갱신
		if (temp > area)
			area = temp;
	}
	return area;
}

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (!n)break;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		// 트리 높이 계산
		int h = (int)(ceil(log2(n)) + 1e-9);
		int tree_size = (1 << (h + 1));
		// 트리 배열 선언
		vector<int> tree(tree_size);
		init(a, tree, 1, 0, n - 1);
		cout << largest(a, tree, 0, n - 1) << '\n';
	}
}
