// 4. Median of Two Sorted Arrays
// Hard
// 23.3K
// 2.6K
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// function median(a,b){

//     let x = [...a,...b].sort((a,b) => a-b );
//     let mid = Math.floor(x.length/2)
//     if (x.length%2 === 0){
//         return (x[mid] + x[mid-1])/2
//     }else{
//         return x[mid]
//     }

//  return mid
// }

let  nums1 = [1,3], nums2 = [2]
// console.log(median(nums1, nums2))

function factorial(n){
    if(n<2){
        return 1;
    }
    
    return n * factorial(n-1)
}

console.log(factorial(6))