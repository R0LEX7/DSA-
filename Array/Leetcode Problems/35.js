
// 35. Search Insert Position
// Easy
// 13.2K
// 574
// Companies
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

function insertPos(nums, target) {
    let n = nums.length;
    let s = 0;
    let e = n-1 ;

    while (s<=e) {
        let mid = Math.floor((s+e) /2);

        if(nums[mid] < target && nums[mid +1] > target) {
            return mid + 1;
        }else if(nums[mid] > target ){
            e = mid - 1;
        }else if(nums[mid] < target){
            s = mid + 1;
        }else{
            return mid
        }
    }
    return s
}

let nums = [1,3,5,6], target = 0
console.log(insertPos(nums, target))