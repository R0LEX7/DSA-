function isPalindrome(s) {
  let n = s.length;
  s = s.toLowerCase();

  let i = 0;
  let j = n - 1;

  while (i <= j) {
    if (s[i] !== s[j]) {
      console.log("in if");
      return false;
      break;
    } 
      i++;
      j--;
    
  }

  return true;
}

let a = "abcbA";
console.log(isPalindrome(a));


