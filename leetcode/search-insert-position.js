/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  // 이분 탐색 초기 인덱스
  let start = 0;
  let end = nums.length - 1;

  // 이분 탐색
  while (start <= end) {
    // 중간 인덱스 구하기
    let mid = Math.floor((start + end) / 2);
    // 중간값이 target과 일치하면 해당 인덱스 리턴
    if (nums[mid] === target) return mid;
    // 중간값이 타겟보다 작으면 start 갱신, 그렇지 않으면 end 갱신
    if (nums[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  // 이분탐색이 끝날 때 까지 못찾으면
  // 교차한 지점을 반환
  return start;
};
