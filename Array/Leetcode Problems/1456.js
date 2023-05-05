// 1456. Maximum Number of Vowels in a Substring of Given Length
// Medium
// 1.9K
// 67
// Companies
// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

function maxVowels(s,k){

    let vowels = new Set(['a','e','i','o','u']);

    let maxCount = 0;
    let count = 0;

    for (let i = 0; i < k; i++) {
        if(vowels.has(s[i])){
            count ++;
        } 
    }

    maxCount = count ;

    for (let i = k; i< s.length; i++){

        if(vowels.has(s[i])){
            count ++;
        } 
        if(vowels.has(s[i-k])){
            count --;
        } 

    }
    return Math.max(maxCount, count)
}

let s = "aeiou"
console.log(maxVowels(s,2))