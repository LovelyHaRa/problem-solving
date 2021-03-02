#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, longest; // longest=가장 긴 리프 간 노드 길이
vector<int> y, x, radius;

// 트리 구조체
struct TreeNode
{
	vector<TreeNode*> children;
};

// x의 제곱을 반환한다
int pow(int x) { return x * x; }

// a, b간 거리를 구한다
int dist(int a, int b) { return pow(y[a] - y[b]) + pow(x[a] - x[b]); }

// 성벽 a가 성벽 b를 포함하는지 확인한다
bool encloses(int a, int b)
{
	return radius[a] > radius[b] && dist(a, b) < pow(radius[a] - radius[b]);
}

// 성벽 트리에서 parent가 child의 부모인지 확인한다
bool isChild(int parent, int child)
{
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; i++)
		// parent는 child를 꼭 직접 포함해야 한다
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	return true;
}

// root 성벽을 루트로 하는 트리를 생성한다
TreeNode* getTree(int root)
{
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++)
	{
		// ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
		// 트리를 만들고 자손 목록에 추가한다
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}
	return ret;
}

// root를 루트로 하는 서브트리의 높이를 구한다
int height(TreeNode* root)
{
	// 각 자식을 루트로 하는 서브트리 높이를 계산한다
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	// 만약 자식이 하나도 없다면 높이는 0
	if (heights.empty()) return 0;
	// 높이 정렬
	sort(heights.begin(), heights.end());
	int k = heights.size();
	// 리프간 노드의 최대값을 갱신한다
	if (k >= 2)
		longest = max(longest, 2 + heights[k - 2] + heights[k - 1]);
	// 트리의 높이는 서브트리 높이의최대치에 1을 더해 계산한다
	return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로의 길이를 계산한다
int solve(TreeNode* root)
{
	longest = 0;
	// 트리의 높이와 리프 간 노드 길이 중 큰 것을 선택한다.
	int h = height(root);
	return max(longest, h);
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		y.resize(n);
		x.resize(n);
		radius.resize(n);
		for (int i = 0; i < n; i++) cin >> y[i] >> x[i] >> radius[i];
		// 트리 생성
		TreeNode* root= getTree(0);
		cout << solve(root) << '\n';
		y.clear();
		x.clear();
		radius.clear();
	}
}
