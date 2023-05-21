function removeSubstring(str, start, end) {
    str.splice(start, end - start);
  return str;
}

// let x = "himanshu";
// console.log(removeSubstring(s, 1, 3));

function removeOccurrences(s, part) {
    while (s.indexOf(part) !== -1) {
        s = s.slice(0, s.indexOf(part)) + s.slice(s.indexOf(part) + part.length);
    }
    return s;
}

let s = "daabcbaabcbc", part = "abc";
console.log(removeOccurrences(s, part));