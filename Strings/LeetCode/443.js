// let res = [];
// let val = 15;
// res.push((val / 10));
// res.push((val % 10).toString);
// console.log(res)

function singleDigit(n) {
  let ar = [];

  for (let i = 0; i < n.length; i++) {
    const element = n[i];
    ar.push(element);
  }
  return ar;
}

function Compress(chars) {
  let res = [];
  let map = new Map();

  for (let k of chars) {
    if (!map.has(k)) {
      map.set(k, 1);
    } else {
      let count = map.get(k);
      count++;
      map.set(k, count);
    }
  }

  for (let [key, value] of map.entries()) {
    if (value === 1) {
      res.push(key);
    } else {
      res.push(key);
      if (value < 10) {
        value = value.toString();
        res.push(value);
      } else {
        value = value.toString();
        res.push(...singleDigit(value));
      }
    }
  }

  return res;
}

// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

function compress(chars) {
  let writeIndex = 0;
  let count = 1;

  for (let i = 0; i < chars.length; i++) {
    if (i + 1 < chars.length && chars[i] === chars[i + 1]) {
      count++;
    } else {
      chars[writeIndex++] = chars[i];
      if (count > 1) {
        const countStr = count.toString();
        for (let j = 0; j < countStr.length; j++) {
          chars[writeIndex++] = countStr[j];
        }
      }
      count = 1;
    }
  }
  chars.length = writeIndex;

  return chars;
}
let s = ["a", "a", "b", "b", "c", "c", "c"];

console.log(compress(s));
// console.log(singleDigit("1221"))
