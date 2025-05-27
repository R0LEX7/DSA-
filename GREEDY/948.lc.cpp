#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& arr, int p) {
  int n =  arr.size();
  if( n ==0) return 0;

  sort(arr.begin() , arr.end());

  int r = 0 , sc = 0 ,l = n-1;

  if(arr[0] > p) return 0;

  while(r <= l){
    if(arr[r] <= p){
        sc++;
        p -= arr[r];
        r++;
    }else{
        if(r == l) return sc;
        p += arr[l];
        sc--;
        l--;
    }
  }

  return sc;
}


int main(){

    vector <int> arr = {200,100} ;
    int p = 150;

    int ans = bagOfTokensScore(arr , p);
    cout<<ans<<endl;

    return 0;
}
