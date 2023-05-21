// 1572. Matrix Diagonal Sum
// Easy
// 2.5K
// 32
// Companies
// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

// Example 1:

// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.
// Example 2:

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8
// Example 3:

// Input: mat = [[5]]
// Output: 5

// function getCommonelement(mat){
//     if(mat.length % 2 !==0){
//         let index = Math.floor((mat.length) /2)
//         console.log(index)
//         common = mat[index][index];
//         return common;
//     }else{
//         return -1
//     }
// }

function diagonalSum(mat) {
  let n = mat.length;
  let sum = 0;
  let j = n - 1;

  
  for (let i = 0; i < n; i++) {
      const element1 = mat[i][i];
      const element2 = mat[i][j];
      sum += element1 + element2;
      j--;
    }
    
    if (n % 2 !== 0) {
      let index = Math.floor(n / 2);
      
      common = mat[index][index];
      sum -= common;
    }
 
  return sum;
}



let mat = [[5]];
console.log(diagonalSum(mat));