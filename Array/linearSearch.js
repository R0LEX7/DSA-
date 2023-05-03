// console.log("Hey");

function binarySearch(arr, key) {
  let low = 0,
    high = arr.length - 1;

  while (low <= high) {
    let mid = Math.floor((high + low) / 2);
    if (key === arr[mid]) {
      console.log("found", key, "at index: ", mid);
      return true;
    } else if (key > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  console.log("Element not Found ");

  return false;
}
function linearSearch(arr, key) {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === key) {
      console.log("found", key, "at index: ", i);
      return true;
    }
  }
  console.log("Element not Found !!");
  return false;
}

function binarySearch2(arr, key){
  let low = 0 , high = arr.length - 1 ;
  
  if ( low > high){
    return false;
  }
  
  let mid = Math.floor((low + high) /  2);
  
  if (key === arr[mid]){
    console.log("found", key, "at index: ", mid);
    return true;
  }
  else if (key < arr[mid]){
    high = mid -1;
  }
  else{
    low = mid + 1 ; 
  }
  
  console.log("Element not in Array");
  return false
}


let arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
let key = 50;

setTimeout(() => {
  console.log("\nBY LINEAR SEARCH--:");
  linearSearch(arr, 509);
},2000);
setTimeout(() => {
  console.log("\nBY BINARY SEARCH--:");
  binarySearch(arr, 020);
},3000);
setTimeout(() => {
  console.log("\nBY RECURSIVE BINARY SEARCH--:");
  binarySearch2(arr, 500);
},4000);

// binarySearch(arr, key) ? "" : console.log("Element Not Found");
