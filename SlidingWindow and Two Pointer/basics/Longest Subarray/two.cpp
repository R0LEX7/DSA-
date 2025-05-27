// L2. Maximum Points You Can Obtain from Cards | 2 Pointers and Sliding Window

#include <bits/stdc++.h>
using namespace std;

int getMaxPoints(vector<int> arr , int k){

    int lSum = 0 , rSum = 0 , n = arr.size() , maxi = 0 , rInd = n-1;

    for(int i = 0 ; i < k ; i++) lSum += arr[i];

     maxi = lSum;

     for(int i = k-1 ; i>=0 ; i--){
        lSum -= arr[i];
        rSum += arr[rInd];
        rInd--;
     maxi = max(maxi , lSum + rSum);

     }

     return maxi;

}


int main(){

    vector <int> arr = {6,2,13,4,7,2,1,7,5};
    int k = 4;

    int ans = getMaxPoints(arr , k);

    cout<<"Maximum points are "<<ans<<endl;

    return 0;
}
