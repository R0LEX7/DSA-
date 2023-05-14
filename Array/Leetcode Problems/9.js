// Given an integer x, return true if x is a 
// palindrome
// , and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

// function isPalindrome(x){
//     x= x.toString();

//     let y = ""


//     for (let i = x.length -1 ; i >=0 ; i--) {
//         const element = x[i];
//         y += element ;  
//     }
//     console.log(typeof(y))      
    
//     return (y === x)
// }

function isPalindrome(x) {

    if(x < 0){
        return false;
    }

    let og = x;
    let pal = 0 ;

    while (og > 0){
        pal = pal*10  + (og % 10)  

        og = Math.floor(og / 10)
    }

    return (x === pal)
}

let x = -11;

console.log(isPalindrome(x))