#include <bits/stdc++.h>
using namespace std;

vector <int> help(vector <int> id  , vector <int> freq){
    int n = id.size() ;
    unordered_map <int , int> map;
    vector<int> ans(n , 0);

    for (int i = 0; i < n; i++){
        map[id[i]] =map[id[i]] + freq[i];
        int maxi = INT_MIN ;
        for(int x : id){

            if(map[x] > maxi){
                maxi = map[x];

            }
        }


        ans[i] = maxi == INT_MIN ? 0 : maxi;

    }

    return ans;

}


int main(){

    vector<int>  nums = {2,3,2,1}, freq = {3,2,-3,1};

    vector <int> ans = help(nums , freq);

    for(int x : ans){
        cout<<x<<endl;
    }

    return 0;
}
