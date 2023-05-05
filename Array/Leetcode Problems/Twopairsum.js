// function twoPairSum(arr, k) {
//   let result = [];

//   for (let i = 0; i < arr.length; i++) {
//     const element = arr[i];
//     let temp = k - element;
//     if (arr.includes(temp)) {
//       result.push([element, temp]);
//     }
//   }

//   result.length = result.length / 2

//   return result;
// }

function twoPairSum(arr, k) {
    let result = [];
    let numMap = new Map();
  
    for (let i = 0; i < arr.length; i++) {
      const element = arr[i];
      let temp = k - element;
  
      if (numMap.has(temp)) {
        result.push([element, temp]);
      }
  
      numMap.set(element, i);
    }
  
    // result.length = result.length / 2;
  
    return result;
  }
  
let num = [2,5,7,4,6];

console.log(twoPairSum(num , 9))