/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
  // cache[n]: n번째 계단을 오를 수 있는 경우의 수
  const cache = new Array(n + 1).fill(0);
  // 초기값 세팅
  cache[1] = 1;
  cache[2] = 2;
  // 점화식: cache[n] = cache[n - 1] + cache[n - 2]
  for (let i = 3; i <= n; i++) {
    cache[i] = cache[i - 1] + cache[i - 2];
  }

  return cache[n];
};
