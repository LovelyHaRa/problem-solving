/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function (n) {
  let cur = n; // 자릿수 제곱의 합을 구할 수
  let set = new Set(); // 합을 저장하기 위한 집합
  while (true) {
    let sum = 0; // 자릿수 제곱의 합
    // 자릿수 탐색
    while (cur) {
      sum += parseInt(Math.pow(cur % 10, 2)); // 자릿수 추출 후 더하기
      cur = parseInt(cur / 10); // 다음 자릿수 계산
    }
    // 1이면 happy number
    if (sum === 1) return true;
    // 합을 저장한 집합에 이미 있으면 무한루프가 발생하므로
    // happy number가 될 수 없다
    if (set.has(sum)) return false;
    // 집합에 합 추가
    set.add(sum);
    // 자릿수 제곱의 합을 구할 수를 갱신
    cur = sum;
  }
};
