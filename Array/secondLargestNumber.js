arr = [1, 12, 12 , 17, 4, 5, 16];

function secondLargestFun(arr) {
  let firstLargest = Math.max();
  let secondLargest = Math.max();

  if(arr.length <2){
    return null
  }

  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > firstLargest) {
      secondLargest = firstLargest;
      firstLargest = arr[i];
    } else if (arr[i] > secondLargest && arr[i] < firstLargest) {
      secondLargest = arr[i];
    }
  }

  return secondLargest;
}


let arr2 = [ 2,3,6,6,5]

console.log(secondLargestFun(arr2));

console.log(-2 > -1)