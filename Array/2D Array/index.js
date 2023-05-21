const readline = require("readline");

const r1 = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function takeInput1() {
  r1.question("Enter the number of rows : ", (rows) => {
    console.log(`rows are  ${rows}`)
    // r1.question("Enter the number of columns : ", (col) => {
    //   const matrix = [];

    //   for (let i = 0; i < rows; i++) {
    //     let row = [];
    //     for (let j = 0; j < col; j++) {
    //       r1.question(`Enter the element at ${i} : ${j} `, (elem) => {
    //         row.push(elem);

    //     });
    //         // if (row.length === col) {
    //         //   matrix.push(row);
    //         //   if (matrix.length === rows) {
    //         //     console.log(`input matrix is ${matrix}`);
    //         console.log(row)
    //             r1.close();
    //         //   }
    //         // }
    //     }
    //   }
    // });
    r1.close()
  });
}

const prompt = require('prompt-sync')();

function takeInput() {
  const rows = parseInt(prompt('Enter the number of rows: '));
  const cols = parseInt(prompt('Enter the number of columns: '));
  const matrix = [];

  for (let i = 0; i < rows; i++) {
    const row = [];

    for (let j = 0; j < cols; j++) {
      const element = parseInt(prompt(`Enter the element at position [${i}][${j}]: `));
      row.push((element));
    }

    matrix.push(row);
  }

  console.log('Input matrix:', matrix);
//   console.log(rowSum(matrix))
const key = parseInt(prompt('Enter the key value : '));

console.log(isIncludes(matrix,key))
}

takeInput();

function rowSum(arr){

    let maxSum = 0;
    let maxRow = -1;


    for (let i = 0; i < arr.length; i++) {
        let sum = 0;
        for (let j = 0; j < arr[i].length; j++) {
           sum += arr[i][j];
        //    return sum; 
        }
        
        if(sum > maxSum) {
            maxSum = sum;
            maxRow = i
        }
        
    }

    return `max row ${maxRow} sum ${maxSum}`;
}

function isIncludes(mat , key){



    for (let i = 0; i < mat.length; i++) {
        for (let j = 0; j < mat[i].length; j++) {
            if(mat[i][j] === key) {
                return true;
            }
        }
        
    }

    return false;
}