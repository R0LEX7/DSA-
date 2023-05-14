// 1. Two Sum
// Easy
// 45.9K
// 1.5K
// Companies
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]


function twoSum(nums,target){

    let myMap = new Map();
    let result = []
    
    for(let i = 0; i < nums.length; i++){
        let value = target - nums[i];
        if(myMap.has(value)){
            result.push( myMap.get(value),i);
        }else{
            myMap.set(nums[i],i)
        }
    }

    return result
}

let arr = [2,7,11,15], target = 9;

console.log(twoSum(arr, target))