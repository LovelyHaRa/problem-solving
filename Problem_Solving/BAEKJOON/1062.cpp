#include<iostream>
#include<string>

using namespace std;

string words[50];
int n, k, res;

// 현재 알파벳 사전, 배워야할 알파벳, 지금까지 배운 알파벳 수의 정보를 가지고
// 글자를 읽을 수 있는지 확인한다 
void readWord(int dic, int alpha, int cnt)
{	
	// 글자를 배울 수 있을만큼 배웠다면
	if (cnt == k)
	{
		int canRead = 0; // 읽을 수 있는 단어 개수
		for (int i = 0; i < n; i++)
		{
			int j;
			for (j = 4; j < words[i].size() - 4; j++)
			{
				// 해당 글자가 사전에 없다면 브레이크
				if (!(dic & 1 << words[i][j] - 97))
					break;
			}
			// 끝까지 수행하면 읽을 수 있음을 의미
			if (j == words[i].size() - 4) canRead++;
		}
		// 최대값 갱신
		res = res < canRead ? canRead : res;
		return;
	}
	// 완전 탐색
	for (int i = alpha; i < 26; i++)
	{
		// 알파벳을 배우지 않은 상태라면
		if (!(dic & 1 << i))
		{
			// 사전에 추가
			dic |= 1 << i;
			// 다음지점 탐색
			readWord(dic, i + 1, cnt + 1);
			// 원상복구
			dic &= ~(1 << i);
		}
	}
}

int main(void)
{
	int dic = 0; // 비트마스크 알파벳 사전
	// 사전에 접두사, 접미사 알파벳 추가
	for (char c : {'a', 'n', 't', 'i', 'c'})
		dic |= 1 << c - 97;
	cin >> n >> k;
	// k가 5 미만이면 글자를 배울 수 없다
	if (k - 5 < 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	// k가 26이면 모든 글자를 배울 수 있다
	if (k == 26)
	{
		cout << n << '\n';
		return 0;
	}
	k -= 5; // 이미 접두사, 접미사 알파벳을 배웠다
	// 단어 입력
	for (int i = 0; i < n; i++)
		cin >> words[i];
	readWord(dic, 0, 0);
	cout << res << '\n';
}
