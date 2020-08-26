#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// 선형 합동 난수 생성기
struct RNG
{
	int seed, a, b;
	RNG(int _a, int _b) :a(_a), b(_b), seed(1983) {}
	int next()
	{
		int ret = seed; // 기존 시드
		seed = ((seed*(long long)a) + b) % 20090711; // 새 시드 생성
		return ret; // 기존 시드 리턴
	}
};

int runningMedian(int n, RNG rng)
{
	// 힙 생성
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0; // 중간값 합계 저장
	// 불변식
	// 1. maxHeap 크기는 minHeap 크기보다 항상 작거나 같다
	// 2. maxHeap 루트는 minHeap 루트보다 항상 작거나 같다
	for (int i = 0; i < n; i++)
	{
		// 1번 불변식 만족시키기
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		// 2번 불변식이 만족되지 않으면 양쪽 루트를 swap
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
		{
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		// 중간값 누적
		ret = (ret + maxHeap.top()) % 20090711;
	}
	// 리턴
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		RNG rng(a, b);
		cout << runningMedian(n, rng) << '\n';
	}
}