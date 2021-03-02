#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int l, c;
vector<char> pw, selected;
vector<int> visited;

// 순열 생성
void permutation(int cnt)
{
	// 기저 사례: 목표 길이에 도달했을 때
	if (cnt == l)
	{
		// 자/모음 체크
		int con = 0, vow = 0;
		for (int i = 0; i < l; i++)
		{
			if (selected[i] == 'a' || selected[i] == 'e' || selected[i] == 'i' || selected[i] == 'o' || selected[i] == 'u')
				vow++;
			else
				con++;
			if (con > 1 && vow > 0) break;
		}
		// 자음 2개미만 또는 모음이 없으면 출력 안함
		if (con <= 1 || vow == 0) return;
		// 순열 출력
		for (int i = 0; i < l; i++)
			cout << selected[i];
		cout << '\n';
		return;
	}
	for (int i = 0; i < c; i++)
	{
		// 순열은 오름차순이어야 한다
		if (visited[i] || (cnt > 0 && selected[cnt - 1] > pw[i])) continue;
		visited[i] = 1; // 방문 체크
		selected[cnt] = pw[i]; // 순열 원소 추가
		permutation(cnt + 1); // 다음 지점 탐색
		visited[i] = 0; // 원상 복구
	}
}

int main(void)
{
	cin >> l >> c;
	pw.resize(c);
	visited.resize(c);
	selected.resize(l);
	for (int i = 0; i < c; i++)
		cin >> pw[i];
	// 정렬
	sort(pw.begin(), pw.end());
	permutation(0);
}
