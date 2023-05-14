var rotate = function(nums, k) {
    let temp = [];

    for(let i = 0 ; i < nums.length; i++){
        temp[(i+k) % nums.length] = nums[i];
    }

    nums = temp
    return nums;
};

console.log(rotate([1,2,3,4,5] , 0))
console.log(rotate([1,2,3,4,5] , 2))
console.log(rotate([1,2,3,4,5] , ))