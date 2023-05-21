
// 204. Count Primes
// Medium
// 6.8K
// 1.3K
// Companies
// Given an integer n, return the number of prime numbers that are strictly less than n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0



var countPrimes = function(n) {

    if(n<2){
        return 0;
    }
    
    let count = 0;
    let isPrime = new Array(n).fill(true);

    isPrime[0] = isPrime[1] = false;

    for(let i = 2; i*i < n; i++) {
        if(isPrime[i]){
            // If i is prime, mark all its multiples as non-prime
            for(let j = 2*i ; j < n; j+= i) {
                isPrime[j] = false;
        }
    }

};
for(let k = 2 ; k < n; k++){
    if(isPrime[k]){
        count++;
    }
}
return count;
}

console.log(countPrimes(10))