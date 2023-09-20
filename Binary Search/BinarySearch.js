// function binarySearch(a , k){
//     let n = a.length;
//     let low = 0;
//     let high = n - 1;

//     let mid = 0

//     while(low <= high){
//         mid = Math.floor((low + high) / 2);
//         console.log("mid" ,mid)

//         if(a[mid] === k){
//             return mid;
//         }else if(a[mid] < k){
//             low = mid +1;
//         }else {
//             high = mid - 1;
//         }
//     }

//     return -1;
// }

// question to find first and last position of an element
function firstOccurrence(a, k) {
  let n = a.length;
  let ans = -1;
  let low = 0;
  let high = n - 1;

  let mid = 0;

  while (low <= high) {
    mid = Math.floor((low + high) / 2);
    console.log("mid", mid);

    if (a[mid] === k) {
      ans = mid;
      high = mid - 1;
    } else if (a[mid] < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}
function lastOccurrence(a, k) {
  let n = a.length;
  let ans = -1;
  let low = 0;
  let high = n - 1;

  let mid = 0;

  while (low <= high) {
    mid = Math.floor((low + high) / 2);
    console.log("mid", mid);

    if (a[mid] === k) {
      ans = mid;
      low = mid + 1;
    } else if (a[mid] < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

let arr = [1, 3, 4, 5, 6, 6, 6, 7, 8];

console.log([firstOccurrence(arr, 6), lastOccurrence(arr,6)]);
