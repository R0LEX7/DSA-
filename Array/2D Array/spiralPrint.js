function spiralOrder(matrix) {
  let row = matrix.length;
  let col = matrix[0].length;
  let total = row * col;
  let count = 0;
  let startingRow = 0;
  let startingCol = 0;
  let endingRow = row - 1;
  let endingCol = col - 1;
  let result = [];

  while (count < total) {
    //  starting row

    for (let i = startingCol; count < total && i <= endingCol; i++) {
      result.push(matrix[startingRow][i]);
      count++;
    }
    startingRow++;

    //  ending col

    for (let i = startingRow; count < total && i <= endingRow; i++) {
      result.push(matrix[i][endingCol]);
      count++;
    }
    endingCol--;

    //  ending row

    for (let i = endingCol; count < total && i >= startingCol; i--) {
      result.push(matrix[endingRow][i]);
      count++;
    }
    endingRow--;

    //  starting col

    for (let i = endingRow; count < total && i >= startingRow; i--) {
      result.push(matrix[i][startingCol]);
      count++;
    }
    startingCol++;
  }

  return result;
}

let arr = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
];
matrix = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12],
];
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7];
console.log(spiralOrder(matrix));
