function getMatrix(n) {
  let matrix = [];
  let total = n * n;
  let count = 1;
  let startingRow = 0;
  let startingCol = 0;
  let endingRow = n - 1;
  let endingCol = n - 1;

    // Initialize matrix with empty subarrays
    for (let i = 0; i < n; i++) {
        matrix.push([]);
      }

  while (count <= total) {
    //  starting row

    for (let i = startingCol; count <= total && i <= endingCol; i++) {
      matrix[startingRow][i] = count
      count++;
    }
    startingRow++;

    //  ending col

    for (let i = startingRow; count <= total && i <= endingRow; i++) {
      matrix[i][endingCol] = count
      count++;
    }
    endingCol--;

    //  ending row

    for (let i = endingCol; count <= total && i >= startingCol; i--) {
      matrix[endingRow][i] = count
      count++;
    }
    endingRow--;

    //  starting col

    for (let i = endingRow; count <= total && i >= startingRow; i--) {
      matrix[i][startingCol] = count
      count++;
    }
    startingCol++;
  }

  return matrix;
}

console.log(getMatrix(3));
