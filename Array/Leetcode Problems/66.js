function plusOne (digits){
    let num = (Number(digits.join("")) + 1).toString().split("").map(Number);


return num ;
}


let arr = [1, 2, 3];
console.log(plusOne(arr));