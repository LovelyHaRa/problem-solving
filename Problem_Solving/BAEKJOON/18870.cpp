#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n; // 입력 받기
	// 좌표 데이터, 정렬 후 데이터
	vector<int> x(n), sorted(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sorted[i] = x[i];
	}
	// 좌표 데이터 정렬
	sort(sorted.begin(), sorted.end());
	// unique를 사용하여 중복 데이터 뒤로 보내기
	// 반환 값은 맨 뒤로 이동된 중복값의 첫 번째 위치
	// 이를 erase를 이용하여 제거한다
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	// 좌표 압축
	for (auto i : x)
	{
		// 이분 탐색으로 정렬된 데이터에서 위치 찾기
		auto pos = lower_bound(sorted.begin(), sorted.end(), i);
		// begin 이터레이터를 빼 줌으로써 위치 출력
		cout << pos - sorted.begin() << ' ';
	}
	cout << '\n';
}