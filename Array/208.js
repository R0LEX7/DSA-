function moveZeroes(nums) {
  let n = nums.length;

  let i = 0;
  let j = 0;

  while (j < n) {
    if (nums[j] !== 0) {
      [nums[i], nums[j]] = [nums[j], nums[i]];
      i++;
    }

    j++;
  }

  return nums;
}

let a = [1, 0, 1];
let b = [0, 1, 0, 3, 12];
console.log(moveZeroes(a));
