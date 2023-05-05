

// To remove duplicates from a sorted array in place, you can use the two-pointer approach. The idea is to maintain two pointers - one pointing to the current element being considered for removal, and the other pointing to the next unique element in the array. As we traverse through the array, if we encounter a duplicate element, we simply skip over it by moving the first pointer. If we encounter a new unique element, we move the second pointer forward and swap the element at that index with the next unique element.

function removeDuplicacy(nums){

    if (!nums.length) {
        return 0;
      }
    let i = 0 ;

    for (let j = 0; j < nums.length; j++) {
        if(nums[j] !== nums[i]){
            nums[++i] = nums[j];
        }
    }
    nums.length = i+1;
    return (i + 1), nums ;
}

let nums = [1, 1, 2];

console.log(removeDuplicacy(nums))