function numSubseq  (nums , target){
    let n = nums.length;
    let low = 0;
    let high = n-1 ;
    let count = BigInt(0); 

    let mod = BigInt(1e9 + 7);

    nums = nums.sort((a,b) => a-b)

    while(low <= high){

        if(nums[low] + nums[high] <= target){
            count = (count + BigInt(Math.pow(2, high-low))) % mod;
            low++;
        }else{
            high--
        }


    }

    return Number(count) ;
}

let arr = [3,3,6,8];
let target = 10;

console.log(numSubseq(arr, target))