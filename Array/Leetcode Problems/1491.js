// 491. Average Salary Excluding the Minimum and Maximum Salary
// Easy
// 2K
// 171
// Companies
// You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

// Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
// Example 2:

// Input: salary = [1000,2000,3000]
// Output: 2000.00000
// Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
// Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

function average(salary) {
  let max = 0;
  let min = 10 ** 6 + 1;
  let sum = 0;
  for (let i = 0; i < salary.length; i++) {
    if (salary[i] > max) {
      max = salary[i];
      x = i;
    }
    if (salary[i] < min) {
      min = salary[i];
      y = i;
    }
    sum += salary[i];
  }

  return (sum - (min + max)) / (salary.length - 2);
}

let salary = [8000, 9000, 2000, 3000, 6000, 1000];

console.log(average(salary));
