#include <bits/stdc++.h>
using namespace std;

int help( int n , int ex){

    int sum = 0, x = n;

    while(x > 0){
        sum += x;
         int temp = (x/ex) + (x % ex);
         x = temp;
    }

    return sum;

}


int main(){

    int ans = help(15 , 4);

    cout<<ans;

    return 0;
}
