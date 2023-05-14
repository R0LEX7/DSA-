// 121. Best Time to Buy and Sell Stock
// Easy
// 25.1K
// 792
// Companies
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

function maxProfit(prices) {
  let n = prices.length;
  let x = Math.min(...prices);

  //  if lowest price is on last day there is no profit
  if (x === prices[n - 1]) {
    console.log(x)
    return 0;
  }

  let max = Math.max();

  for (let a = prices.indexOf(x); a < n; a++) {
    if (prices[a] > max) {
      max = prices[a];
      console.log(max);
    }
  }

  let profit = max - x;

  return profit;
}

let prices = [2,4,1];
// console.time()
console.log(maxProfit(prices));
// console.time()
