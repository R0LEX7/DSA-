#include <bits/stdc++.h>
using namespace std;

bool winnerOfGame(string s) {
        int n = s.length() , x = 0;

        for(int i = 1 ; i < n  ; i+2){
            if(s[i] + s[i-1] + s[i+1] == 'A'*3) x++;
        }

        return x> 0;
    }


int main(){

    return 0;
}