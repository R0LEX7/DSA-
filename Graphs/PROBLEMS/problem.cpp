#include <bits/stdc++.h>
using namespace std;

int help (vector<int> p , vector<int> a , int k){
    int n = p.size();

    int sum = 0 , maxi = INT_MIN;

    for( int i = 0 ; i < n ; ++i){
        if(a[i]) sum += p[i];
    }



    for(int i = 0 ; i < k ; ++i){
        if(!a[i]) sum += p[i];
    }

    for(int i = 0 ; i < n - k ; ++i){
        if (!a[i]) sum -= p[i];

        // Add the effect of the element coming into the window
        if (!a[i + k]) sum += p[i + k];
        maxi = max(sum , maxi);

    }

    return maxi;
}


int main(){

    vector <int> p = {1,3,5,2,5,4} , a = {1,1,0,1,0,0};

    int ans = help(p , a , 3);


    cout<< ans;


    return 0;
}