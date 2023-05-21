

function  isPrime(n){

    if(n < 2){
        return false;
    }

    for(let i = 2 ; i <= Math.floor(n/2) ; i++){
        if(n % i === 0){
            return false;
            break;
        }
    }
    return true;
}

function primeNumbers(a , b){

    let ar = []

    for(let i = a ; i <= b ; i++){
        if(isPrime(i)){
            ar.push(i)
        }
    }

    return ar
}

let a = 9;
let b = 22;
console.log(primeNumbers(0,10))
// console.log(isPrime())