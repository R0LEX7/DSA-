// Kadane's algorithm is a popular algorithm for finding the maximum subarray sum in an array of integers. 
// the  steps of this algorithm are 
// (a) : initialize sum = 0 and maxi = arr[0]
//  (b) : for loop in arr for(let i = 0; i < arr.length; i++)
        // sum = sum + arr[i];
        // maxi = Math.max(maxi,sum);
// (c) if sum < 0 set sum = 0
// return maxi


function maxSubArray(arr){
    // step 1
    let sum = 0;
    let maxi = arr[0];
    for(let i =0 ; i < arr.length ; i++){
        // step 2
      sum = sum + arr[i];
      maxi = Math.max(maxi,sum);
       // step 3
      if(sum < 0){
        sum = 0
      }
    }
    
    return maxi ;
  }
  
  let num = [-2,-3,4,-1,-2,1,5,-3];
  
  let output = `Given Array : [${num}] \n and \n the largest sum of contigous subarray is ${maxSubArray(num)}` ;
  
  console.log(output);