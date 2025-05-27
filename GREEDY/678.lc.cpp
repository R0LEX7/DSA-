#include <bits/stdc++.h>
using namespace std;


// recursive code
// bool isValid(string s , int ind , int cnt){
//     int n = s.size();

//     if(ind == n) return cnt == 0;

//     if(cnt < 0) return false;

//     char curr = s[ind];

//     if(curr == '(') return isValid(s , ind+1 , cnt+1);
//     if(curr == ')') return isValid(s , ind+1 , cnt-1);

//     return isValid(s , ind+1 , cnt+1) || isValid(s , ind+1 , cnt-1) || isValid(s , ind+1 , cnt);
// }

bool isValid(string s){
    int n = s.size() , max = 0 , min = 0 ;

    for (int i = 0; i < n; i++)
    {
        char curr = s[i];

        if(curr == '(') {
            max++;
            min++;
        }else if( curr == ')'){
            min--;
            max--;
        }else {
            // * occurs
            min--;
            max++;
        }

        if(min < 0) min = 0;
        if(max < 0 ) return false;
    }

    return min == 0;

}


int main(){

    string s = "(*))";

    bool ans = isValid(s);

    cout<<ans<<endl;

    return 0;
}
