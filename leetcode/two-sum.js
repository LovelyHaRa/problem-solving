/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  // 순열 탐색(brute force)
  for (let i = 0; i < nums.length - 1; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      // 두개의 수를 더해서 target이 되면 리턴
      if (nums[i] + nums[j] === target) {
        return [i, j];
      }
    }
  }
};
