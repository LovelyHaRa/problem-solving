
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 백준 3079 풀이 참조
long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long low = 0, high = 0;
	long long maxtime = 0;
	for (int i = 0; i < times.size(); i++)
		maxtime = max((long long)times[i], maxtime);
	high = n * maxtime;
	answer = high;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < times.size(); i++)
			sum += mid / times[i];
		if (sum >= n)
		{
			answer = min(answer, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return answer;
}
