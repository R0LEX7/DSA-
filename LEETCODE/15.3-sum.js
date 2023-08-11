/*
 * @lc app=leetcode id=15 lang=javascript
 *
 * [15] 3Sum
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {

    numns = nums.sort((a,b) => a-b);

    let x = 0 ;

    let mySet = new Set();

    for(let i = 0 ; i < nums.length ; i++) {
        if (i > 0 && nums[i] === nums[i - 1])
            continue;
        let j = i+1;
        let k = nums.length -1 ;
        while(j <k){

            let val = nums[i] + nums[j]  + nums[k];
            if( val === x){
                mySet.add(`${nums[i]},${nums[j]},${nums[k]}`);
                j++;
                k--;
            }else if (val < x){
                j++
            }else{
                k--;
            }
        }
    }

    return Array.from(mySet , triplets => triplets.split(',').map(Number));
    // return mySet;

    
};
// @lc code=end

let ar = [-1,0,1,2,-1,-4];
let br = [-2,0,0,2,2]
console.log(threeSum(br))
let a = "a,b,c";


