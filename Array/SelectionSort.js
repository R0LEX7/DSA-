

const selectionSort = (arr) => {
    let n = arr.length;

    for (let i = 0; i < n-1; i++) {
        let min = Math.min();
        let minIndex = -1;
        
        for (let j = i; j < n; j++){
            const element = arr[j];
            if(element < min){
                min = element;
                minIndex = j
            }  
        }
        const element = arr[i];
        // let temp = arr[i];
        arr[i] = min;
        arr[minIndex] = element;
        
    }

    return arr
}


console.log(selectionSort([1,2,3,4,5]))