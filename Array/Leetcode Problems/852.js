function pivotElement(arr){

    if(arr.length < 3){
        return false;
    }
    let n = arr.length;
    let low = 0;
    let high = n-1;
    let mid ;

    while(low< high){

        mid = Math.floor((low + high)/2);

        if(arr[mid]< arr[mid+1]){
            low = mid + 1;
        }else{
            high = mid;
        }

    }

    return low;

}


let array = [2,3,5,4,1];

console.log(pivotElement(array))