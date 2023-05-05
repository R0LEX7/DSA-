function intersection(a, b) {
  let setA = new Set(a);
  let setB = new Set(b);
  let result = []

  setA.forEach(element => {
    if(setB.has(element)){
        result.push(element);
    }
  });
  return result;
}


let ar1 = [1,2,2,3];
let ar2 = [2,2]

console.log(intersection(ar1, ar2));