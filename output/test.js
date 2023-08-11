

function findOdd(nums){

    for (let i = 0; i < nums.length -1 ; i++) {
        const element = nums[i];
        const next = element + 2;
        console.log("hyy")

        if(nums[i+1] !== next) {
            return next
        }
        
    }

    return false;
}

let arr = [5,7,9,11,15,19];4
console.log(findOdd(arr));