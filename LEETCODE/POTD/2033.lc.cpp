#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
      vector<int> arr ;
      int rem = grid[0][0] % x;
      for(auto& A : grid){
        for(int a : A){
            arr.push_back(a);
            if(a%x != rem) return -1;
        }
      }

      sort(begin(arr) , end(arr));

      int n = arr.size() ,  median =arr[n/2] , steps = 0;

    for(int a : arr){
        if(a==median) continue;
        steps += abs(( median - a))/x;
    }

    return steps;
}


int main(){

    return 0;
}