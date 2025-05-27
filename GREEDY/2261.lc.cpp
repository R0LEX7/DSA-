#include <bits/stdc++.h>
using namespace std;

    int countDistinct(vector<int>& arr, int k, int p) {
        int n = arr.size() ;
        set  <vector<int>> mySet;

        for(int i = 0 ; i < n ; i++){
            vector<int> temp;
            int d = k;
            for(int j = i ; j < n ; j++){
                if(arr[j]%p == 0) d--;
                if(d < 0 ) break;
                temp.push_back(arr[j]);
                if(mySet.find(temp) == mySet.end()){
                    mySet.insert(temp);
                }
            }
        }

        return mySet.size();

    }


int main(){

    return 0;
}