#include<iostream>
#include<vector>

using namespace std;

// 트리 노드 정보(루트, 왼쪽, 오른쪽, 부모 노드)
struct TreeNode {
	int root, left, right, parent;
};
vector<TreeNode> T; // 트리 배열

// 열 번호, 트리 깊이
int colCount = 1, depth = 1;
vector<int> minLev, maxLev; // (min/max)Lev[x]: x 레벨 일 때, 열의 최소/최댓값

int min(int a, int b) { return a < b ? a : b; }

// 중위 순회
void inorder(int node, int level)
{
	TreeNode t = T[node];
	if (depth < level) depth = level; // 트리 깊이 갱신
	// 왼쪽 서브트리 탐색
	if(t.left>0)
		inorder(t.left, level + 1);
	// 레벨별 열의 최소/최댓값 갱신
	minLev[level] = min(minLev[level], colCount);
	maxLev[level] = colCount++;
	// 오른쪽 서브트리 탐색
	if (t.right > 0)
		inorder(t.right, level + 1);
}

int main(void)
{
	int n;
	cin >> n;
	T.resize(n + 1);
	// 초기 세팅
	for (int i = 1; i <= n; i++)
		T[i] = { i,-1,-1,-1 }; // root를 i로 하여 세팅
	minLev.resize(n + 1, n + 1);
	maxLev.resize(n + 1);
	// 트리 노드 추가
	for (int i = 0; i < n; i++)
	{
		int r, a, b;
		cin >> r >> a >> b;
		// 왼쪽 노드가 있을 시
		if (a > 0)
		{
			T[r].left = a; // 왼쪽 노드 저장
			T[a].parent = r; // 부모 정보 갱신
		}
		// 오른쪽 노드가 있을 시
		if (b > 0)
		{
			T[r].right= b; // 오른쪽 노드 저장
			T[b].parent = r; // 부모 정보 갱신
		}
	}
	int root = -1;
	// 최상단 루트 노드 찾기
	for (int i = 1; i <= n; i++)
	{
		// 부모가 없는 노드가 루트 노드
		if (T[i].parent == -1)
		{
			root = T[i].root;
			break;
		}
	}
	// 중위 순회
	inorder(root, 1);
	// 루트 노드는 항상 1레벨, 1의 너비를 가진다
	int lev = 1, width = 1;
	// 2레벨 부터 트리 최대 높이까지 탐색하면서 최대 너비 갱신
	for (int i = 2; i <= depth; i++)
	{
		int cur = maxLev[i] - minLev[i] + 1; // 너비 계산
		// 최댓값 갱신
		if (width < cur)
		{
			lev = i; // 레벨 갱신
			width = cur;
		}
	}
	cout << lev << ' ' << width << '\n';
}