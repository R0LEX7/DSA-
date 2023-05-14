const perfectSquare = function (x) {

    let low = 1;
    let high = x ;

    while(low <=high){
        let mid = Math.floor((high+low)/2);

        let sq =  mid * mid;

        if(sq < x){
            low = mid + 1 ;
        }else if (sq > x){
            high = mid - 1 ;
        }else {
            return true;
        }

    }

    return false;
};
console.log(perfectSquare(0));
