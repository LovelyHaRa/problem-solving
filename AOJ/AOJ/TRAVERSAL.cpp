#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 주어진 배열을 a에서 b구간만큼 잘라 반환
vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

// 트리의 전위탐색 결과와 중위탐색 결과가 주어질 때 후위탐색 결과를 출력한다.
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	// 트리에 포함된 노드 수
	const int N = preorder.size();
	// 기저 사례: 텅 빈 트리면 곧장 종료
	if (preorder.empty()) return;
	// 루트는 전위순회 배열 맨 앞자리
	const int root = preorder[0];
	// 왼쪽 서브트리 크기는 중위탐색 결과에서 루트의 위치를 찾아서 알 수 있다
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	// 왼쪽 서브트리 탐색
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	// 오른쪽 서브트리 탐색
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	// 루트 출력
	cout << root << ' ';
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i < n; i++) cin >> preorder[i];
		for (int i = 0; i < n; i++) cin >> inorder[i];
		printPostOrder(preorder, inorder);
		cout << '\n';
	}
}