//  maximum occurences of a character means "apple" has 1: a 2: p  1:l 1:e max is p two times

function maxOcc(s) {
  let map = new Map();

  for (let key in s) {
    if (!map.has(s[key])) {
      map.set(s[key], 1);
    } else {
      let count = map.get(s[key]);
      count++;
      map.set(s[key], count);
    }
  }
  let foundKey;
  let maxVal = Math.max(...map.values())
  for (let [key, value] of map.entries()) {
    if (value === maxVal) {
       foundKey = key;
      break;
    }
  }

  return foundKey ;
}

let l = "gauravvv";
// console.log(maxOcc(l))

let s = "daabcbaabcbc", part = "abc";
console.log(s.indexOf(part));
console.log(s.substring(2 , 5))
console.log(s.slice(0,2) , s.slice(5,s.length));
