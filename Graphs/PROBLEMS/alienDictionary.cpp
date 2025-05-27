#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      string findOrder(vector<string> &arr) {
        vector<vector<char>> adj;

        for( int i = 0 ; i < arr.size() -1 ; i--){
            for(int j = 0 ; j < arr[i].length() && j < arr[i+1].length() ; ++j){
                if(arr[i][j] == arr[i +1][j]) continue;

                adj.push_back({arr[i][j] - 'a' , arr})
            }
        }
      }
  };

int main(){

    return 0;
}