function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function (root, targetSum) {
  // 노드가 없는 경우 false 리턴
  if (!root) {
    return false;
  }
  // 타겟에서 노드의 값을 빼서 0이 된 순간 해당 노드가 리프노드이면 true 리턴
  if (targetSum - root.val === 0 && !root.left && !root.right) {
    return true;
  }

  // 좌우 노드 재귀 탐색
  return (
    hasPathSum(root.left, targetSum - root.val) ||
    hasPathSum(root.right, targetSum - root.val)
  );
};
