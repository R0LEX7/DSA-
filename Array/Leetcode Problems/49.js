// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

function groupAnagrams(strs) {
  let anagramMap = new Map();

  for (let i = 0; i < strs.length; i++) {
    let sorted = strs[i].split("").sort().join("");
    if (!anagramMap.has(sorted)) {
      anagramMap.set(sorted, [strs[i]]);
    } else {
    //   let anagramList = anagramMap.get(sorted);
    //   anagramList.push(strs[i]);
    //   anagramMap.set(sorted, anagramList);
    anagramMap.get(sorted).push(strs[i]);
    }
  }

  return Array.from(anagramMap.values());
}

let strs = ["eat", "tea", "tan", "ate", "nat", "bat"];

console.log(groupAnagrams(strs));
