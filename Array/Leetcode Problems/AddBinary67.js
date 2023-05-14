function binaryToDecimal(x){
    // x is a string
    let a = 0;

    for(let i = x.length -1 ; i >= 0 ; i--){
        if(x[i] === '1'){
            // console.log("in if else")
            a += 2**(x.length-1 -i);
        }
        // console.log("in loop")
    }

    return a;
}

function addBinary(a,b){
    a = binaryToDecimal(a);
    b = binaryToDecimal(b);

    return (a+b).toString(2);
}


console.log(addBinary("1010","1011" ))