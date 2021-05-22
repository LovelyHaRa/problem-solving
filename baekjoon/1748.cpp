#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n;
	cin >> n; // 길이를 쉽게 알기 위해 문자열로 입력 받음
	int k = 1, i = 1, res = 0; // 자릿수가 바뀔때의 첫번째 숫자(1, 10, 100 ...), 자릿수 이터레이터, 결과
	// 입력받은 숫자의 자릿수보다 하나 작은 수만큼 반복
	while (i < n.length()) {
		// 해당 자릿수의 모든 수를 이어썼을떄의 길이: (자릿수에 해당하는 모든수의 개수 * 자릿수)
		res += k * 9 * i++; 
		k *= 10; // 자리 시작수 갱신
	}
	res += (stoi(n) - k + 1) * i; // 입력받은 수가 자릿수의 몇번째 숫자인지 구한 뒤 자릿수만큼 곱해서 더한다
	cout << res << '\n';
}
