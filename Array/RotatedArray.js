// function rotatedArray(arr, pos) {
//   const n = arr.length;
//   const rotations = pos % n;

//   for (let i = 0; i < rotations; i++) {
//     const last = arr[n - 1];

//     for (let j = n - 1; j > 0; j--) {
//       arr[j] = arr[j - 1];
//     }

//     arr[0] = last;
//   }

//   return arr;
// }

// function rotateArray(arr, k) {
//   const n = arr.length;
//   const rotations = k % n;

//   function reverse(i, j) {
//     while (i < j) {
//       [arr[i], arr[j]] = [arr[j], arr[i]];
//       i++;
//       j--;
//     }
//     return arr;
//   }

//   // return reverse( 0 , n)
// }

var rotate = function(nums, k) {
    k %= nums.length // if k is greater than nums.length then one cycle is completed that means it will remain the same and we have to remainder shifts
     
    let reverse = function(i, j){
     while(i < j){
         let temp = nums[i]
         nums[i] = nums[j]
         nums[j] = temp
         i++
         j--
     }
    } // suppose  ----->---> 
     reverse(0, nums.length-1); // reverse   <--<------
      reverse(0, k-1) // reverse first part ---><----
    reverse(k, nums.length-1)// reverse second part --->----->
    return arr 
 };

let arr = [1, 2, 3, 4, 5, 6, 7];
console.log(rotate(arr, 3));
