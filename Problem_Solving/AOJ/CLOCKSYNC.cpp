#include<iostream>
#include<vector>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."};

bool areAligned(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCKS; i++)
		if (clocks[i] != 12) return false;
	return true;
}

void push(vector<int>& clocks, int swtch)
{
	for (int clock = 0; clock < CLOCKS; clock++)
	{
		if (linked[swtch][clock] == 'x')
		{
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

int min(int a, int b) { return a < b ? a : b; }

int solve(vector<int>& clocks, int swtch)
{
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for (int count = 0; count < 4; count++)
	{
		ret = min(ret, count + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}

int main(void)
{
	int C;
	freopen("input.txt", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> C;
	while (C > 0)
	{
		vector<int> clocks(CLOCKS);
		for (int i = 0; i < CLOCKS; i++)
			cin >> clocks[i];
		int res=solve(clocks,0);
		if (res >= INF)
			cout << "-1" << endl;
		else
			cout << res << endl;
		C--;
	}
}