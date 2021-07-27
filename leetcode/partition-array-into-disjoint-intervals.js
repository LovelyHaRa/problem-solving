/**
 * @param {number[]} nums
 * @return {number}
 */
var partitionDisjoint = function (nums) {
  let partMax = nums[0], // 탐색한 곳 까지의 최대 값
    max = nums[0], // 전체 최대 값
    res = 0;
  // 선형 탐색
  for (let i = 1; i < nums.length - 1; i++) {
    // 탐색한 곳 까지의 최대 값보다 값이 작으면
    if (partMax > nums[i]) {
      res = i; // 인덱스 갱신
      partMax = max; // 탐색한 곳 까지의 최대 값 갱신
    }
    // 전체 최대 값 갱신
    max = Math.max(max, nums[i]);
  }

  // 인덱스 +1 값 리턴
  return res + 1;
};
