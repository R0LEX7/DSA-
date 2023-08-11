function getLetter(s) {
    let letter;
    
    let e = s[0];

    switch(e){
        case "a":
            case "e":
            case "i":
            case "o":
            case "u":
                letter = "A";
                break;
            case "b":
            case "c":
            case "d":
            case "f":
            case "g":
                letter = "B";
                break;
            case "h":
            case "j":
            case "k":
            case "l":
            case "m":
                letter = "C";
                break;
            default:
                letter = "D";

    }


    return letter;
}

let s = "abcd"
 s= s.split("").reverse().join("");
 console.log(s)