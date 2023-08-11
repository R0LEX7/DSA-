

function bsearch(arr , s , e , key){

    let n = arr.length;
    let mid = Math.floor((s+e) /2);

    if(arr[mid] === key){
        return mid;
    }else if (arr[mid] < key){
        return bsearch(arr , mid + 1 , e , key);
    }else{
        return bsearch(arr , s , mid - 1 , key);

    }    
}

let num = [2,5,7,9,10]

let ans = bsearch(num , 0 , num.length-1 , 9);
console.log(ans)