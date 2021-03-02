#include<iostream>
#include<queue>

using namespace std;

// 난수 생성기
struct RNG
{
	unsigned seed;
	RNG() : seed(1983) {} // 생성자
	unsigned next()
	{
		unsigned ret = seed; // 실제로 리턴해야할 값은 이전값
		seed = ((seed * 214013u) + 2531011u); // 다음 값 미리 계산
		return ret % 10000 + 1; // 이전값 리턴
	}
};

// 온라인 알고리즘 활용
int countRanges(int k, int n)
{
	RNG rng; // 난수 생성기
	queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++)
	{
		int newSignal = rng.next(); // 새로운 난수를 받는다
		rangeSum += newSignal; // 구간합에 추가
		range.push(newSignal); // 큐에 현재 난수 삽입

		// 구간합이 k를 초과하면 k 이하가 될 때까지 큐에서 추출 후 구간합에서 삭제
		while (rangeSum > k)
		{
			rangeSum -= range.front();
			range.pop();
		}
		// 구간합이 k인 경우 경우의 수 추가
		if (rangeSum == k) ret++;
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int k, n;
		cin >> k >> n;
		cout << countRanges(k, n) << '\n';
	}
}
