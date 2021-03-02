#include<iostream>
#include<vector>

using namespace std;

int maxEnergy; // 에너지 최대값

//  남은 구슬 배열 w와 지금까지 모은 에너지 e를 바탕으로 에너지를 모은다
void makeEnergy(vector<int> w, int e)
{
	// 기저 사례: 구슬이 2개 남았을 때
	if (w.size() == 2)
	{
		// 최대값 갱신
		maxEnergy = maxEnergy < e ? e : maxEnergy;
		return;
	}
	// 첫 부분과 마지막 부분을 제외하고 탐색
	for (int i = 1; i < w.size() - 1; i++)
	{
		// 부분 에너지 계산
		int pe = w[i - 1] * w[i + 1] + e;
		// 배열 복사
		vector<int> nw = w;
		// 원소 삭제
		nw.erase(nw.begin() + i);
		// 남은 구슬로 에너지 모으기
		makeEnergy(nw, pe);
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	makeEnergy(w, 0);
	cout << maxEnergy << '\n';
}
