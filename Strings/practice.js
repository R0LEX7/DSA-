


function matching(stringList , queries){
    let myMap = new Map();

    for (let i = 0; i < queries.length; i++) {
        const element = queries[i];
        myMap.set(element , 0)
    }

    for (let j = 0; j < stringList.length; j++) {
        const element = stringList[j];
        if(myMap.has(element)) {
            let val = myMap.get(element);
            myMap.set(element, val+1)
        }
    }

 return [...myMap.values()];
}

let stringList = ['ab','ab' , 'abc'];
let que = ['ab', 'abc', 'bc']

console.log(matching(stringList,que))