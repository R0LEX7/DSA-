#include <bits/stdc++.h>
using namespace std;

  int minSwaps(string s) {
    int n = s.length() ,cnt = 0;

    for(int i = 0 ; i < n/2 ; i++){
        if(s[i] == '[') cnt++;
        else {
            if(cnt > 0) cnt--;
        }
     }

     return (cnt + 1)/2;
    }


int main(){

    return 0;
}
