function rotate(matrix){
    let n = matrix.length;

    //  Transpose matrix
    for (let i = 0; i < n; i++) {
       for (let j = i+1; j < n; j++){

        [matrix[i][j] , matrix[j][i] ] = [matrix[j][i], matrix[i][j]]
       }
        
    }

    // reverse each row of matrix
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n/2; j++){
 
         [matrix[i][j] , matrix[i][n-j-1] ] = [matrix[i][n-j-1], matrix[i][j]]
        }
         
     }

     return matrix;
}

let matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]];
console.log(rotate(matrix))