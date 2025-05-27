#include <bits/stdc++.h>
using namespace std;

vector <int> help(vector<vector<int>> arr){
    int n = arr.size();
    vector<int> ans;
    unordered_map <int , int> map;

    for (int i = 0 ; i<n ; i++){
        int m = arr[i].size();

        for(int j = 0 ; j<m ; j++){
            map[arr[i][j]]++;
        }
    }

    for (auto& [key , value] : map){
        if(value == n) ans.push_back(key);
    };

    sort(ans.begin() , ans.end());

    return ans;
}


int main(){

    return 0;
}
