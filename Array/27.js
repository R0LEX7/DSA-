

function removeElement(nums , val ){
    let j = 0 ;

    for (let i = 0; i < nums.length; i++) {
        if(nums[i] !== val){
            nums[j] = nums[i];
            j++;
        }
        
    }
    return nums;
}

let arr = [3,2,3,2]
console.log(removeElement(arr,2))