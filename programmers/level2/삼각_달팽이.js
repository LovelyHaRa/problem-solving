function solution(n) {
  const arr = Array.from(new Array(n), (i) => new Array(n).fill(0));
  let len = n; // 포인터를 반복시켜야할 횟수
  let count = 1; // 숫자 채우기용
  // 삼각 달팽이를 채우기 위한 위치 포인터
  let x = -1,
    y = 0;

  // 다 채우면 종료
  while (len > 0) {
    // 왼쪽 변
    for (let i = 0; i < len; i++) {
      arr[++x][y] = count++;
    }
    // 밑변
    for (let i = 0; i < len - 1; i++) {
      arr[x][++y] = count++;
    }
    // 오른쪽 변
    for (let i = 0; i < len - 2; i++) {
      arr[--x][--y] = count++;
    }
    // 변이 3개이므로 3회 빼주기
    len -= 3;
  }

  // 각 행의 채워진 부분만 출력하고 1차원 배열로 변환
  return arr.map((x, index) => x.slice(0, index + 1)).flat();
}
