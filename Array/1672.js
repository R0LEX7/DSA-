// // Input: accounts = [[1,5],[7,3],[3,5]]
// Output: 10
// Explanation:
// 1st customer has wealth = 6
// 2nd customer has wealth = 10
// 3rd customer has wealth = 8
// The 2nd customer is the richest with a wealth of 10.

// let arr1 = [1,2];
// let arr2 = [2,3];

// console.log(Math.max(...arr1 , ...arr2));

function maximumWealth(accounts) {
    // let maxWealth = 0 ;

    // for (let i = 0; i < accounts.length; i++) {
    //     let currentWealth = 0 ;
    //     for (let k = 0; k < accounts[i].length; k++) {
            
    //         currentWealth = currentWealth + accounts[i][k];
            
    //     }
    //     if(currentWealth > maxWealth) {
    //        maxWealth = currentWealth;
    //     }
        
    // }
    // return maxWealth ;
    let sum =accounts.map(customer => customer.reduce((a, b) => a + b));
    return Math.max(...sum)
}

let arr = [[6,5],[7,3,4],[3,5]];

console.log(maximumWealth(arr));