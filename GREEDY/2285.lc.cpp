#include <bits/stdc++.h>
using namespace std;

long long maximumImportance(int n, vector<vector<int>>& arr) {

        long long sum = 0;
        vector<pair<int , int>> deg ;
        unordered_map<int , int> map;

        for(vector<int> vn : arr){
            map[vn[0]]++;
            map[vn[1]]++;
        }

        for(int i = 0 ; i < n ; i++){
            deg.push_back({i , map[i]});
        };

        sort(deg.begin() , deg.end() , [](pair<int ,int> & a , pair <int,int> &b){
            return a.second > b.second;
        });

        unordered_map<int , int> imp;

        for(int i = 0 ; i < n ; i++){
            imp[deg[i].first] = n-i;
        }

         for(vector<int> vn : arr){
             sum += (long long) imp[vn[0]] + imp[vn[1]];
        }
    return sum;

    }


int main(){

    return 0;
}