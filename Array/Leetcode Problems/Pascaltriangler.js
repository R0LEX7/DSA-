function pascalTriangle(n) {
  if (n === 0) {
    return [];
  }
  if (n === 1) {
    return [[1]];
  }

  let result = [];

  for (let row = 1; row <= n; row++) {
   let arr = [];

        for (let col = 0; col < row; col++) {
            
            if(col === 0 || col === row-1){
                 arr.push(1)
            } else {
                arr.push((result[row-2][col-1] + result[row-2][col]))
            }
            
        }

        result.push(arr)
    
  }
  return result;
}


function getRow(n) {
    if (n === 0) {
        return [1];
      }
      if (n === 1) {
        return [1,1];
      }
    
      let result = [];
    
      for (let row = 1; row <= n+1; row++) {
       let arr = [];
    
            for (let col = 0; col < row; col++) {
                
                if(col === 0 || col === row-1){
                     arr.push(1)
                } else {
                    arr.push((result[row-2][col-1] + result[row-2][col]))
                }
                
            }
    
            result.push(arr)
        
      }
      return result[n]; 
}

// console.time()
console.log(getRow(3))
// console.time()
