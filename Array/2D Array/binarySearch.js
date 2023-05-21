var searchMatrix = function(matrix, target) {
    
    let m = matrix.length;
    let n = matrix[0].length;
    let low = 0;
    let high = m*n -1

    let mid = -1;

    while(low <= high) {
        mid = Math.floor((low + high) /2);

        let element = matrix[Math.floor(mid/n)][mid % n];

        if(element > target){
            high = mid -1;
        }else if(element < target){
            low = mid + 1;
        }else if (element === target){
            return true
        }
    }

    return false
};

let ar = [ [ 7, 4, 1 ], [ 8, 5, 2 ], [ 9, 6, 3 ] ];
console.log(searchMatrix(ar , ))