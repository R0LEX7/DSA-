// Divide Two Integers
// Medium
// 4.3K
// 13.3K
// Companies
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

function divide(dividend, divisor) {
  if (divisor === 0) {
    return Infinity;
  }
  if (dividend === -2147483648 && divisor === -1) {
    return 2147483648;
  }
  if(divisor === 1){
    return dividend;
  }

  let sign = 1;

  if (dividend < 0) {
    dividend = -dividend;
    sign = -sign;
  }

  if (divisor < 0) {
    divisor = -divisor;
    sign = -sign;
  }

  let quotient = Math.floor(Math.exp(Math.log(dividend) - Math.log(divisor)));

  

  return sign * quotient;
}


console.log(divide(1000000000,1))