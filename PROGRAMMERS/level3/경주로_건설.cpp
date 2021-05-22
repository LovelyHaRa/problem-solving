#include <string>
#include <vector>
#include <queue>

using namespace std;

// 큐에 저장할 도로 정보
struct Road {
    int x, y, cost, dir; // 좌표, 이제까지 설치된 비용, 방향(0, 1, 2, 3)
    // 생성자
    Road(int _x, int _y, int _cost, int _dir) : x(_x), y(_y), cost(_cost), dir(_dir) {}
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> build(n, vector<int>(n)); // build[x][y]: (x, y)까지 건설된 최소 비용
    int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // 상하좌우 이동 증가량
    // 초기 큐 생성
    queue<Road> q;
    Road road(0, 0, 0, -1); // 시작지점은 어디로 가도 직선 도로이기 때문에 예외로 한다
    q.push(road);
    // BFS 탐색
    while (!q.empty()) {
        // 큐에서 추출
        Road curRoad = q.front();
        q.pop();
        // 상하좌우 이동
        for (int i = 0; i < 4; i++) {
            // 다음 좌표
            int nx = curRoad.x + dx[i], ny = curRoad.y + dy[i];
            // 다음 좌표까지의 설치 비용
            int nextCost = curRoad.cost;
            // 범위를 벗어나거나 벽인 경우 건너뛰기
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]) continue;
            // 시작점이거나, 방향이 같은 경우
            if (curRoad.dir == -1 || curRoad.dir == i) {
                nextCost += 100;
            }
            // 방향이 다른 경우(역방향, 좌, 우)
            else if (curRoad.dir != i) {
                nextCost += 600;
            }
            // 처음 방문 하거나 현재 건설된 비용이 새로 계산된 비용보다 비쌀 경우
            if (!build[nx][ny] || build[nx][ny] >= nextCost) {
                build[nx][ny] = nextCost; // 비용 갱신
                // 큐에 추가
                Road nextRoad(nx, ny, nextCost, i);
                q.push(nextRoad);
            }
        }
    }
    return build[n - 1][n - 1];
}
