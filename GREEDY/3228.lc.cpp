#include <bits/stdc++.h>
using namespace std;

int help (string arr){
    int cnt = 0 , n = arr.size() , l;
    //to get the last index of zero
    for(int i = n-2 ; i>=0 ; i--){
        if(arr[i] == '0'){
            l = i;
            break;
        }
    }

    for(int i = n-2 ; i>=0 ; i--){
        if(arr[i] == '1'){
            swap(arr[i] , arr[l]);
            l = i;
            cnt++;
        }
    }

    return cnt;

}


int main(){

   string s = "1001101";
    int ans = help(s);

    cout<<ans;

    return 0;
}
