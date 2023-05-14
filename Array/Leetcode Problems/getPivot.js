

function findPivot(arr){
    let n = arr.length;
    let s =0 ;
    let e = n-1;
    let mid;

    while(s<e){
        mid = Math.floor((s+e)/2);

        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }else{
            e = mid
        }
    }

    return s;
}

function isRotated(arr){
    // let p = findPivot(arr);
    // let sorted = arr.sort((a,b)=> a-b)
    // console.log(sorted)

    // let removed = arr.splice(0,p);
    // return (sorted === removed.concat(arr))

    let p = findPivot(arr);
    if(p === arr.length){
        return true;
    }
    let sorted = arr.slice().sort((a, b) => a - b);

    let removed = arr.slice(0, p);
    console.log( "removed " , removed);
    let remaining = arr.slice(p);
    console.log( "rem " , remaining);

    let concatenated = remaining.concat(removed);
    let concatenatedStr = concatenated.join(',');
    let sortedStr = sorted.join(',');

    return concatenatedStr === sortedStr;
}




let arr = [1,2,3];
console.log(findPivot(arr))
console.log("XXXXXXXXXXXXXXXXXXXXXX")
console.log(isRotated(arr))