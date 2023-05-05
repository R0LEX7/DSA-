// he complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

function find_Complement(n) {
  n = n.toString(2);

  let output = "";

  for (let i = 0; i < n.length; i++) {
    n[i] === "0" ? (output += "1") : (output += "0");
  }

  output = parseInt(output, 2);

  return output;
}


function findComplementOptimized(n){
    let mask = 1 ;

    while(mask < n){
        mask = (mask << 1) | 1;
    }

    return n^mask;
}

let num = 6;

console.log(findComplementOptimized(num));
