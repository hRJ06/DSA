/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  s = s.trim();
  words = s.split(" ");
  n = words.length;
  for (let i = n - 1; i >= 0; i--) {
    if (words[i] != " ") return words[i].length;
  }
  return 0;
};
