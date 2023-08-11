/*
 * @lc app=leetcode id=202 lang=javascript
 *
 * [202] Happy Number
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {

    let mySet = new Set();
    
    while(n!==1 && !mySet.has(n)){
        let x = 0;
        mySet.add(n)
        while(n!==0){
            x += (n%10) * (n%10);
          n = Math.floor(n/10)
       }
       n = x;
    }


  return n === 1  
};
// @lc code=end

console.log(isHappy(2))