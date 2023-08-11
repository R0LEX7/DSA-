function gcd(a, b) {
  if (a === 0) {
    return b;
  }

  if (b === 0) {
    return a;
  }

  while (a !== 0 && b !== 0) {
    if (a < b) {
      b %= a;
    }
    /* The `if (a > b)` statement is checking if `a` is greater than `b`. If `a` is greater than `b`, then the remainder of
    `a` divided by `b` is assigned to `a` using the modulo operator `%=`. This is because the greatest common divisor of
    `a` and `b` will be the same as the greatest common divisor of `b` and the remainder of `a` divided by `b`. */
    if (a > b) {
      a %= b;
    }
  }

  return a||b;
}

/* `let ans = gcd(127,25);` is calling the `gcd` function with arguments `127` and `25`, and assigning the returned value
to the variable `ans`. The `gcd` function calculates the greatest common divisor of the two numbers using the Euclidean
algorithm. In this case, the value of `ans` will be `1`. */
let ans = gcd(127,25);
console.log(ans);
