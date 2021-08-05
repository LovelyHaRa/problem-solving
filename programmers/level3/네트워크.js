const visit = new Array(200).fill(false);

const dfs = (start, computers, n) => {
  visit[start] = true; // 방문 체크
  // 연결된 모든 노드 탐색
  for (let i = 0; i < n; i++) {
    if (!visit[i] && computers[start][i]) {
      // dfs 탐색
      dfs(i, computers, n);
    }
  }
};

function solution(n, computers) {
  let answer = 0;
  // 노드 개수만큼 dfs 탐색
  for (let i = 0; i < n; i++) {
    if (!visit[i]) {
      dfs(i, computers, n);
      answer++;
    }
  }
  return answer;
}
