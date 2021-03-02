#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int h, w, r, c;
int blockSize;
vector< vector<pair<int, int>>> rotations;
vector<vector<int>> covered;

// 블록을 회전시킨다
vector<string> rotate(const vector<string>& arr)
{
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[0].size(); j++)
			ret[j][arr.size() - i - 1] = arr[i][j];
	return ret;
}

// 블록의 상대좌표를 모두 저장한다
void generateRotations(vector<string> block)
{
	rotations.clear();
	rotations.resize(4);
	// 총 4개
	for (int rot = 0; rot < 4; rot++)
	{
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); i++)
			for (int j = 0; j < block[i].size(); j++)
				if (block[i][j] == '#')
				{
					// 좌상단 좌표를 구한다
					if (originY == -1)
					{
						originY = i;
						originX = j;
					}
					// 좌상단 좌표 기준 상대좌표를 저장한다.
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
		block = rotate(block); // 블록을 90도 회전시킨다.
	}
	sort(rotations.begin(), rotations.end()); // 정렬
	// 중복되는 블럭을 제거한다.
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size(); // 블럭 자체의 개수를 구한다
}

int best;
// (y,x)에 블럭을 놓을 수 있는지 여부를 반환, delta로 블럭을 넣거나 뺀다.
bool set(int y, int x, const vector<pair<int, int>>& block, int delta)
{
	bool res = true;
	for (int i = 0; i < block.size(); i++)
	{
		// 좌표가 범위 안에 포함되면
		if (y + block[i].first >= 0 && y + block[i].first < h && x + block[i].second >= 0 && x + block[i].second < w)
		{
			covered[y + block[i].first][x + block[i].second] += delta; // 블럭 넣기/빼기
			res = res && (covered[y + block[i].first][x + block[i].second] == 1); // 넣은 위치가 검은색이면 2일 것 이다
		}
		else res = false;
	}
	return res;
}

// 가지치기
int blockPrune(int placed)
{
	int cnt = 0;
	// 보드에 넣을 수 있는 칸의 개수를 구한다.
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cnt += !(covered[i][j]) ? 1 : 0;
	}
	// 칸의 개수 / 블럭단위 개수 + 넣은 블럭의 개수가 best보다 작으면 이 경우는 최적해를 찾을 수 없다
	return ((cnt / blockSize) + placed <= best);
}

void search(int placed)
{
	// 가지치기
	if (blockPrune(placed))
		return;
	// 좌상단부터 최초의 빈 공간을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0;j < w; j++)
		{
			if (covered[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	// 기저 사례: 모든 칸이 채워져 있으면 최대값 갱신 후 리턴
	if (y == -1)
	{
		best = max(best, placed);
		return;
	}
	// 블럭을 넣어본다
	for (int i = 0; i < rotations.size(); i++)
	{
		// 블럭 채우기
		if (set(y, x, rotations[i], 1))
			search(placed + 1); // 채울 수 있으면 카운팅 하고 재귀탐색
		set(y, x, rotations[i], -1); // 블럭 빼기
	}
	covered[y][x] = 1; // 이 칸을 덮지 않고 막아둔다
	search(placed);
	covered[y][x] = 0;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> h >> w >> r >> c;
		vector<string> block(r);
		covered.resize(h, vector<int>(w));
		// 보드판 정보를 1, 0으로 치환 후 저장
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char x;
				cin >> x;
				covered[i][j] = (x == '#') ? 1 : 0;
			}
		}
		for (int i = 0; i < r; i++)
			cin >> block[i];
		// 블록의 상대좌표 저장
		generateRotations(block);
		best = 0;
		search(0);
		cout << best << '\n';
		rotations.clear();
		covered.clear();
	}
}
