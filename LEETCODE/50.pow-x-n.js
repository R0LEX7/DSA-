/*
 * @lc app=leetcode id=50 lang=javascript
 *
 * [50] Pow(x, n)
 */

// @lc code=start
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function (x, n) {
  if (n == 1 || x === 1) {
    return x;
  }

  if (n < 0) {
    x = 1 / x;
    n = -n;
  }

  let res = 1;

  while (n > 0) {
    if (n & 1) {
      res *= x;
    }

    x *= x;
    n = Math.floor(n / 2);
  }

  return res;
};
// @lc code=end

console.log(myPow(2, 2));
