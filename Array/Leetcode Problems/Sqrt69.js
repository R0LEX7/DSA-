var mySqrt = function(x) {
    let s = 0;
    let e = x;
    let mid = BigInt(0) ;
    let ans = BigInt(-1)
    while(s<e){
        mid = Math.floor((s+e)/2);
        let sq = BigInt(mid*mid);

        if(sq > x){
            e = mid -1;
        }else if(sq< x){
            ans = mid;
            s = mid + 1;
        }else {
            return mid;
        }
    }
    
    return ans;
};

console.log(mySqrt(8))