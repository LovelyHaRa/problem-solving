#pragma once
#include<vector>

// 펜윅 트리의 구현. 가상의 배열 A[]의 부분합을
// 빠르게 구현할 수 있도록 한다.
// 초기화시에는 A[]의 원소가 전부 0이라고 생각한다
template<typename T>
struct fenwick_tree
{
	std::vector<T> tree;
	fenwick_tree(int n) : tree(n + 1) {}
	// pos 까지의 부분합을 구한다
	T sum(int pos)
	{
		// 인덱스는 1부터 시작
		pos++;
		int ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			// 최종 비트를 지우는 연산
			pos &= (pos - 1);
		}
		return ret;
	}
	// A[pos]에 val을 더한다
	void add(int pos, T val)
	{
		pos++;
		while (pos < tree.size())
		{
			tree[pos] += val;
			// 마지막 비트를 추출해 더하는 연산
			pos += (pos&-pos);
		}
	}
};
