

function reverse(s){
    let n = s.length

    for (let i = 0; i < n; i++) {
        [s[i], s[i + 1]] = [s[i+1], s[i]]
        
    }

    return  s.split('').reverse().join('');
}

console.log(reverse('hello'))