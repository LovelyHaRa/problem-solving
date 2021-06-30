/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
  // 해시 테이블 생성
  const hashTable = new Set();

  // board 전체 탐색(O(n^2))
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      // 스도쿠 칸이 비어있지 않다면
      if (board[i][j] !== ".") {
        //각 스도쿠 조건별 해시값 생성
        const row = `${board[i][j]} in row ${i}`;
        const col = `${board[i][j]} in col ${j}`;
        const subBox = `${board[i][j]} in sub-box ${Math.floor(
          i / 3
        )}, ${Math.floor(j / 3)}`;
        // 이미 해시테이블에 포함되어있다면 유효하지 않은 스도쿠
        if (hashTable.has(row) || hashTable.has(col) || hashTable.has(subBox)) {
          return false;
        }
        // 해시테이블에 삽입
        hashTable.add(row);
        hashTable.add(col);
        hashTable.add(subBox);
      }
    }
  }
  return true;
};
