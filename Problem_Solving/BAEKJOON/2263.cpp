#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> inorder, postorder, position;

// 트리의 중위탐색 결과와 후위탐색 결과가 주어질 때 전위탐색 결과를 출력한다.
void printPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
	// 기저 사례: 텅 빈 트리면 곧장 종료
	if (inStart > inEnd || postStart > postEnd) return;
	// 루트는 후위순회 배열 맨 뒷자리
	const int root = postorder[postEnd];
	// 중위탐색 결과에서 루트 위치 검색
	int p = position[root];
	// 왼쪽 서브트리 크기 구하기
	int L = p - inStart;
	// 루트 출력
	cout << root << ' ';
	// 왼쪽 서브트리 탐색
	printPreOrder(inStart, p - 1, postStart, postStart + L - 1);
	// 오른쪽 서브트리 탐색
	printPreOrder(p + 1, inEnd, postStart + L, postEnd - 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	inorder.resize(n+1);
	postorder.resize(n+1);
	position.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> inorder[i];
	for (int i = 1; i <= n; i++) cin >> postorder[i];
	// position[i]= 중위탐색 결과 i노드의 위치
	for (int i = 1; i <= n; i++) position[inorder[i]] = i;
	printPreOrder(1, n, 1, n);
	cout << '\n';
}