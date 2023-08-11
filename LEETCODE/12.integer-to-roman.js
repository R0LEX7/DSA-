/*
 * @lc app=leetcode id=12 lang=javascript
 *
 * [12] Integer to Roman
 */

// @lc code=start
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {

    let ones = ["", "I" , "II" , "III" , "IV" , "V" , "VI" , "VII" , "VIII" , "IX" ];
    let tens = ["" , "X" , "XX", "XXX" , "XL" , "L" , "LX" , "LXX" , "LXXX" , "XC" ];
    let huns = ["" , "C" , "CC" , "CCC" , "CD" , "D" , "DC" , "DCC" , "DCCC" , "CM"];
    let thaus = ["" , "M" , "MM" , "MMM"];

    return thaus[Math.floor(num/1000)]+ huns[Math.floor((num%1000) /100)] + tens[Math.floor((num%100)/10)] + ones[Math.floor(num%10)]
    
};
// @lc code=end

let x = 1994
/* `let ans = intToRoman(x);` is calling the `intToRoman` function with the argument `x` and storing the returned value in
the variable `ans`. */
let ans = intToRoman(x);
console.log(ans)

