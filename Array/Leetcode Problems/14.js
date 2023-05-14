strs.sort();

  let result = "";
  let j = 1;

  if (strs.length === 1) {
    result = strs[0];
  } else {
    let firstWord = strs[0];

    for (const char of firstWord) {
      let isCommon = true;

      for (let i = j; i < strs.length; i++) {
        if (strs[i][result.length] !== char) {
          isCommon = false;
          break;
        }
      }

      if (isCommon) {
        result += char;
      } else {
        break;
      }
    }
  }

  return result;

let strs = ["a"];

console.log(longestCommonPrefix(strs));
