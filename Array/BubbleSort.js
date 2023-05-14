function bubbleSort(arr) {
  let n = arr.length;

  for (let i = 1; i < n; i++) {
    let isSwapped = false;

    for (let j = 0; j < n - i; j++) {
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
        isSwapped = true;
        console.log("inside inner loop")
      }
    }

    if(!isSwapped){
        break;
    }
  }
  return arr;
}


let nums = [7,6,8,9,2,1];
console.log(bubbleSort(nums));