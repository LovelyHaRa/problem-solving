/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  // 0으로 초기화된 길이 26의 배열
  const sArr = new Array(26).fill(0);
  const tArr = new Array(26).fill(0);

  // 각 문자열의 알파벳 개수를 저장한다
  for (let i = 0; i < s.length; i++) {
    sArr[s.charCodeAt(i) - 97]++;
  }
  for (let i = 0; i < t.length; i++) {
    tArr[t.charCodeAt(i) - 97]++;
  }
  // anagram이 되려면 각 알파벳 개수가 모두 같아야 한다
  for (let i = 0; i < 26; i++) {
    if (sArr[i] !== tArr[i]) {
      return false;
    }
  }
  return true;
};
