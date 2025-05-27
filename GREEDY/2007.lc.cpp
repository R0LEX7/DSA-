#include <bits/stdc++.h>
using namespace std;

 vector<int> findOriginalArray(vector<int>& arr) {

    unordered_map<int , int> map;

    vector<int> ans;

    sort(arr.begin() , arr.end());

    for( int x : arr) map[x]++;

    for(int n : arr){
        if(n%2 == 0){
            int half = n/2;
        if(map.find(half) != map.end()){
            map[half]--;
            map[n]--;
            if(map[half] == 0) map.erase(half);
            if(map[n] == 0) map.erase(n);
            ans.push_back(half);
        }
        }
    }

    if(!map.empty()) return {};

    return ans;

    }


int main(){

    return 0;
}
