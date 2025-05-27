#include <bits/stdc++.h>
using namespace std;\


int help (vector<int> arr){
    int n = arr.size() , sum = 0 , right = 1;

    vector<int> left(n);
    left[0] = 1;

    // for left

    for(int i = 1 ; i < n ; i++){
        if(arr[i] > arr[i-1]) left[i] = left[i-1] +1 ;
        else left[i] = 1;
    }
    // for right

    for(int i = n-2 ; i >=0 ; i--){
        if(arr[i] > arr[i+1]) right = right + 1;
        else right = 1;
        sum += max(left[i] , right);
    }

    return sum + max(left[n-1] , 1);


}


int main(){

    vector <int> arr  = {1,2,2};

    int ans = help(arr);

    cout<< "max candies " <<ans<<endl;

    return 0;
}
