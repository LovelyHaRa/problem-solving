#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// 각 접미사들의 첫 t글자를 기준으로 한 그룹 번호가 주어질 때,
// 주어진 두 접미사를 첫 2*t글자를 기준으로 비교한다.
// group[]은 길이가 0인 접미사도 포함한다.
struct Comparator
{
	const vector<int>& group; // 그룹정보
	int t; // 첫 글자의 2배수
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {} // 생성자
	// 연산자 오버로딩(비교함수 정의)
	bool operator () (int a, int b)
	{
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

// s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s)
{
	int n = s.size(); // 문자열 길이
	// group[i]=접미사들을 첫 t글자를 기준으로 정렬했을 때, s[i..]가 들어가는 그룹 번호
	// t=1일 때는 정렬할 것 없이 s[i..]의 첫 글자로 그룹 번호를 정해 줘도 같은 효과가 있다.
	int t = 1;
	vector<int> group(n + 1);
	// t=1일 때 그룹 배열 처리
	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1; // 마지막은 항상 작은 값으로 하면 배열의 오버플로우에 대한 예외처리를 안해도 된다.
	// 결과적으로 접미사 배열이 될 반환 값. 이 배열을 lg(n)번 정렬한다.
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i; // 접미사 시작점 저장
	while (t < n)
	{
		// group[]은 첫 t글자를 기준으로 계산해 뒀다.
		// 첫 2t글자를 기준으로 perm을 다시 정렬한다.
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		// 2t글자가 n을 넘는다면 이제 접미사 배열 완성
		t *= 2;
		if (t >= n) break;
		// 2t글자를 기준으로 한 그룹 정보를 만든다.
		// 새로운 그룹 배열 초기화
		vector<int> newGroup(n + 1); 
		newGroup[n] = -1;
		newGroup[perm[0]] = 0; // 첫번째 접미사는 항상 그룹 0번부터 시작
		for (int i = 1; i < n; i++)
		{
			// 이전 접미사와 글자가 다르면 다른 그룹
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1; // 그룹 번호 추가
			// 반대의 경우 같은 그룹이므로 그룹 번호 복사
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup; // 그룹 배열 갱신
	}
	return perm; // 리턴
}

// s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다
int commonPrefix(const string& s, int i, int j)
{
	int k = 0; // 카운팅
	while (i < s.size() && j < s.size() && s[i] == s[j])
	{
		i++;
		j++;
		k++;
	}
	return k;
}

// k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다.
int longestFrequent(int k, const string& s)
{
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); i++)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int k;
		cin >> k;
		string s;
		cin >> s;
		cout << longestFrequent(k, s) << '\n';
	}
}