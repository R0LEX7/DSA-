var searchMatrix = function (matrix, target) {
  let m = matrix.length;
  let n = matrix[0].length;

  let rowIndex = 0;
  let colIndex = n - 1;

  while (rowIndex < m && colIndex >= 0) {
    let element = matrix[rowIndex][colIndex];

    if (element === target) {
      return 1;
    }

     if (element < target) {
      rowIndex++;
    } else {
      colIndex--;
    }
}
return 0;
};

let matrix = [
    [1, 4, 7, 11, 15],
    [2, 5, 8, 12, 19],
    [3, 6, 9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30],
  ],
  target = 1;
console.log(searchMatrix(matrix, target));
