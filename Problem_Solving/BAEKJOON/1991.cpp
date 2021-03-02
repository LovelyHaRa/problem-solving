#include<iostream>

using namespace std;

struct TreeNode {
	char label;
	TreeNode *left, *right;
};

// 트리에 노드 추가
void add(TreeNode* t, char r, char left, char right)
{
	if (t == NULL) return;
	// 노드를 찾았으면 서브트리 생성
	if (t->label == r)
	{
		// 왼쪽 서브트리 생성
		if (left != '.')
		{
			t->left = new TreeNode();
			t->left->label = left;
		}
		// 오른쪽 서브트리 생성
		if (right != '.')
		{
			t->right = new TreeNode();
			t->right->label = right;
		}
		return;
	}
	// 서브 트리 탐색
	else
	{
		add(t->left, r, left, right);
		add(t->right, r, left, right);
	}
}

void preorder(TreeNode* T)
{
	if (T == NULL) return;
	cout << T->label;
	preorder(T->left);
	preorder(T->right);
}

void inorder(TreeNode* T)
{
	if (T == NULL) return;
	inorder(T->left);
	cout << T->label;
	inorder(T->right);
}

void postorder(TreeNode* T)
{
	if (T == NULL) return;
	postorder(T->left);
	postorder(T->right);
	cout << T->label;
}

int main(void)
{
	TreeNode* T = new TreeNode(); // 트리 초기화
	T->label = 'A'; // 루트는 항상 A
	int n;
	cin >> n;
	while (n--)
	{
		char r, a, b;
		cin >> r >> a >> b;
		add(T, r, a, b); // 트리에 노드 추가
	}
	preorder(T);
	cout << '\n';
	inorder(T);
	cout << '\n';
	postorder(T);
	cout << '\n';
}
