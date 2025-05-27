#include <bits/stdc++.h>
using namespace std;

bool help (vector<int> arr){

    int maxInd = 0;
    int n = arr.size();

    for(int i = 0 ; i < n ; i++){
        if( i > maxInd ) return false;

        maxInd = max(maxInd , arr[i] + i);
    }

    return true;

}


int main(){

    vector <int> arr = {1,2,3,1,1,0,2,5};

    cout<<help(arr)<<endl;

    return 0;
}
