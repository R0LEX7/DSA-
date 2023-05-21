function validString(str) {
  let res = "";
  for (let ch of str) {
    if (ch >= "a" && ch <= "z" || ch >= "0" && ch <= "9") {
      res += ch;
    } else if (ch >= "A" && ch <= "Z") {
      res += ch.toLowerCase();
    } 
  }
  return res;
}
var isPalindrome = function (s) {
  if (s.length < 2) {
    return true;
  }
  let str = validString(s);
  let n = str.length;
  let i = 0;
  let j = n - 1;
  while (i <= j) {
    if (str[i] !== str[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
};
