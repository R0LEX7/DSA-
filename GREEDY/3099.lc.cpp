#include <bits/stdc++.h>
using namespace std;

int help(int n){
    int x = n  , sum = 0;

    while( x > 0){
        int dig = x%10;
        x = x/10;
        sum+= dig;
    }

    return n%sum == 0 ? sum : -1;
}


int main(){

    int ans = help(23);

    cout<<ans<<endl;

    return 0;
}
