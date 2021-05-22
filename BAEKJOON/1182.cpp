#include<cstdio>
#include<vector>

using namespace std;

int n, s;
vector<int> v;
int res = 0;

// dfs 이용
void dfs(int i, int sum)
{
	if (i == n) return; // 기저 조건
	if (sum + v[i] == s) res++;
	
	dfs(i + 1, sum); // 현재 수를 선택 안하는 경우
	dfs(i + 1, sum + v[i]); // 현재 수를 선택 하는 경우
}

int main(void)
{
	scanf("%d %d", &n, &s);
	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	dfs(0, 0);
	printf("%d", res);
}
