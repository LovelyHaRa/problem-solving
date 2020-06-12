#pragma once
#include<vector>

template<typename T>
T min(T a, T b) { return a < b ? a : b; }

const int hugeNum = 1987654321;

template<typename T>
struct range_min_query
{
	int n; // 배열의 길이
	std::vector<T> rangeMin; // 구간별 최솟값 저장
	range_min_query(const std::vector<T>& array)
	{
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	// node 노드가 array[left..right]배열을 표현할 때,
	// node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다
	T init(const std::vector<T>& array, int left, int right, int node)
	{
		// 기저사례: 범위 길이가 1인 경우
		if (left == right)
			return rangeMin[node] = array[left];
		// 구간별로 나눈다
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	// // node가 표현하는 범위 array[left..right]가 주어질 때,
	// 이 범위와 array[left..right]의 교집합의 최소치를 구한다
	T query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		// 두 구간이 겹치지 않으면 아주 큰 값 반환: 무시됨
		if (right < nodeLeft || nodeRight < left) return (T)hugeNum;
		// node가 표현하는 번위가 array[left..right]에 완전히 포함되는 경우
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		// 양쪽 구간을 나눠서 푼 뒤 결과를 합친다
		int mid = (nodeLeft + nodeRight) / 2;
		return min<T>(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	// 인터페이스
	T query(int left, int right) { return query(left, right, 1, 0, n - 1); }
};