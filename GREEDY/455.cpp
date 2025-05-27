#include <bits/stdc++.h>
using namespace std;

int func(vector <int> arr1 , vector <int> arr2){
    sort(arr1.begin() , arr1.end());
    sort(arr2.begin() , arr2.end());
    int i = 0 , j = 0 , m = arr2.size() , ans = 0;;

    while(j<m){
        if(arr2[j] >= arr1[i]){
            ans++;
            i++;
        }
        j++;
    }
    return ans ;
}


int main(){

    vector<int> s = {1,5,3,3,4} , g = {4,2,1,2,1,3};

    int ans = func(s , g);

    cout<<ans<<endl;

    return 0;
}
