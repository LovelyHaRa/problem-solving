/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
  // s의 길이만큼 탐색(또는 t)
  for (let i = 0; i < s.length; i++) {
    // 현재 단어가 처음 사용된 지점 구하기
    const sCur = s.indexOf(s[i]);
    const tCur = t.indexOf(t[i]);

    // 치환적용했을 때 값이 다르면 false
    if (s[tCur] !== s[i] || t[sCur] !== t[i]) {
      return false;
    }
  }
  return true;
};
