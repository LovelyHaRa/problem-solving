#pragma once
#include<cstdlib>
#include<utility>

template<typename T>
struct TripNode
{
	// 노드에 저장된 원소
	T key;
	// 이 노드를 루트로 하는 서브트리의 크기
	int priority, size;
	// 두 자식 노드의 포인터
	TripNode *left, *right;
	// 생성자에서 난수 우선순위를 생성하고 size와 left/right를 초기화한다
	TripNode(const T& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
	void setLeft(TripNode* newLeft) { left = newLeft; calcSize(); }
	void setRight(TripNode* newRight) { right= newRight; calcSize(); }
	// size 멤버를 갱신한다
	void calcSize()
	{
		size = 1;
		if (left) size += left->size;
		if (right)size += right->size;
	}
};

template<typename T>
// root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는 두 개의 트립으로 분리한다
std::pair<TripNode<T>*, TripNode<T>*> split(TripNode<T>* root, T key)
{
	if (root == NULL) return std::pair<TripNode<T>*, TripNode<T>*>(NULL, NULL);
	// 루트가 key 미만이면 오른쪽 서브트리를 쪼갠다
	if (root->key < key)
	{
		std::pair<TripNode<T>*, TripNode<T>*> rs = split(root->right, key);
		root->setRight(rs.first);
		return std::pair<TripNode<T>*, TripNode<T>*>(root, rs.second);
	}
	// 루트가 key 이상이면 왼쪽 서브트리를 쪼갠다
	std::pair<TripNode<T>*, TripNode<T>*> ls = split(root->left, key);
	root->setLeft(ls.second);
	return std::pair<TripNode<T>*, TripNode<T>*>(ls.first, root);
}

template<typename T>
//  root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의 루트를 반환한다
TripNode<T>* insert(TripNode<T>* root, TripNode<T>* node)
{
	if (root == NULL) return node;
	// node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라 각각 자손으로 한다
	if (root->priority < node->priority)
	{
		std::pair<TripNode<T>*, TripNode<T>*> splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

template<typename T>
// a와 b가 두 개의 트립이고, max(a) < min(b)일 때 이 둘을 합친다
TripNode<T>* merge(TripNode<T>* a, TripNode<T>* b)
{
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

template<typename T>
// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다
TripNode<T>* erase(TripNode<T>* root, T key)
{
	if (root == NULL) return root;
	// root를 지우고 양 서브트리를 합친 뒤 반환한다
	if (root->key == key)
	{
		TripNode<T>* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

template<typename T>
// root를 루트로 하는 트리 중에서 k번째 원소를 반환한다
TripNode<T>* kth(TripNode<T>* root, int k)
{
	// 왼쪽 서브트리의 크기를 우선 계산한다
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

template<typename T>
// key보다 작은 키값의 수를 반환한다
int countLessThan(TripNode<T>* root, T key)
{
	if (root == NULL) return0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}
