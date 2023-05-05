// Input: nums1 = [1,2,3], nums2 = [2,4,6]
// Output: [[1,3],[4,6]]

function difference(nums1, nums2) {
  
    let ans1 = new Set(nums1);
    
    nums2.forEach(element => {
        ans1.delete(element);
    });
    
    let ans2 = new Set(nums2);
    nums1.forEach(element => {
        ans2.delete(element);
    })

    return [[...ans1],[...ans2]]
}

let nums1 = [1, 2, 3],
  nums2 = [2, 4, 6];
console.log(difference(nums1, nums2));
