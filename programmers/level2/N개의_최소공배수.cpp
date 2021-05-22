#include <string>
#include <vector>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
	if (a > b) return gcd(a%b, b);
	if (!a) return b;
	return gcd(b%a, a);
}

int solution(vector<int> arr) {
	// 첫번쨰와 두번째 원소의 최소공배수를 구하고
	// 그 최소공배수와 다음 원소의 최소공배수를 구하는 작업을
	// 마지막 원소까지 구하면 N개의 최소공배수를 구할 수 있다.
	int lcm = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		lcm = lcm * arr[i] / gcd(lcm, arr[i]);
	}
	return lcm;
}
