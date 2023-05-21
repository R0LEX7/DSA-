

function reverse(s){
    let n = s.length

    // for (let i = 0; i < n; i++) {
    //     [s[i], s[i + 1]] = [s[i+1], s[i]]
        
    // }

    // return  s.split('').reverse().join('');

    for (let i = 0; i < Math.floor( n/2); i++) {
        
        [ s[i] , s[n-1-i] ] = [s[n-1-i] , s[i]]
        
    }

    return s;
}

console.log(reverse('hello'))