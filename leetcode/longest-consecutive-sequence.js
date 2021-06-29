/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
  // 탐색(O(1))을 위한 set 생성
  const setNum = new Set(nums);

  let max = 0; // return할 최대 길이

  // nums 탐색(O(n))
  nums.forEach((num) => {
    // 기저사례: 집합에 수가 삭제되었다면 리턴
    if (!setNum.has(num)) {
      return;
    }

    // 이전, 다음 수
    let prev = num - 1;
    let next = num + 1;
    setNum.delete(num);

    // 이전 수를 계속 감소시키면서 집합에서 제거
    while (setNum.has(prev)) {
      setNum.delete(prev);
      prev--;
    }
    // 다음 수를 계속 증가시키면서 집합에서 제거
    while (setNum.has(next)) {
      setNum.delete(next);
      next++;
    }

    // 길이(next-prev-1) 갱신
    max = Math.max(max, next - prev - 1);
  });

  return max;
};
