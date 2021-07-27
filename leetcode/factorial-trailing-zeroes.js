/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function (n) {
  let two = 0,
    five = 0;

  // 2의 제곱수를 포함하는 숫자의 개수를 누적한다
  for (let i = 2; i <= n; i *= 2) {
    two += Math.floor(n / i);
  }
  // 5의 제곱수를 포함하는 숫자의 개수를 누적한다
  for (let i = 5; i <= n; i *= 5) {
    five += Math.floor(n / i);
  }
  // 둘 중 작은게 0의 개수가 된다
  return Math.min(two, five);
};
