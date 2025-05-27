#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int n = binary.size();

    for (int i = 0; i < n; ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, n - i - 1);
        }
    }

    return decimal;
}

int help (string s){

    if(s[0] == 1) return 0;
    int val = binaryToDecimal(s) , steps = 0;;

    while(val !=1){
        if(val&1){
            // odd
            val += 1;
        }else{
            val = val/2;
        }
        steps++;
    }

    return steps;
}


int main(){

    string s = "1";
    int ans = help(s);
    cout<<ans<<endl;

    return 0;
}
