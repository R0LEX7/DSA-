function reverseArray(arr , m){
    // m is the position after which we have to reverse the array
    let n = arr.length;

    let i = m+1;
    let j = n -1;

    while(i<j){
        [arr[i] , arr[j]] = [ arr[j] , arr[i] ];
        i++;
        j--;
    }

    return arr;
}

let nums = ["h","e","l","l","o"];
console.log(reverseArray(nums,-1))