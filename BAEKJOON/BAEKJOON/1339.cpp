#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> alpha(26); // alpha[x]: x번째 알파벳의 자릿수만을 가지고 계산한 값
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		int p = 1; // 자릿수(1, 10, 100...)
		// 뒷자리부터 계산
		for (int j = word.size() - 1; j >= 0; j--)
		{
			alpha[word[j] - 'A'] += p; // 해당 알파의 자릿수를 누적시킴 
			p *= 10; // 자릿수 갱신
		}
	}
	sort(alpha.begin(), alpha.end(), greater<int>()); // 알파벳 배열 내림차순 정렬
	int num = 9, res = 0;
	// 9부터 시작하여 정렬된 배열에 곱해주고 하나씩 감소시킨다.
	for (int i = 0; i < alpha.size(); i++)
		res += alpha[i] * num--;
	cout << res << '\n';
}