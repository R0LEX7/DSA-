// This function takes an array as input and sorts it using the insertion sort algorithm
function insertionSort(arr) {
  // Get the length of the array
  let n = arr.length;

  // Set the starting index to 1
  let i = 1;

  // Loop through the array from the second element to the end
  while (i < n) {
    // Save the current element in a temporary variable
    let temp = arr[i];
    // Set the comparison index to the previous element
    let j = i - 1;

    // Loop backwards through the sorted portion of the array
    while (j >= 0) {
      // If the current element is less than the comparison element,
      // shift the comparison element one position to the right
      if (arr[j] > temp) {
        arr[j + 1] = arr[j];
      } else {
        // If the current element is greater than or equal to the comparison element,
        // we have found the correct position for the current element
        break;
      }

      // Decrement the comparison index
      j--;
    }

    // Insert the current element into its correct position
    // j+1 because j is decremented
    arr[j + 1] = temp;
    // Move to the next element
    i++;
  }

  // Return the sorted array
  return arr;
}

let nums = [10, 7, 3, 5, 4, 1];
console.log(insertionSort(nums));
