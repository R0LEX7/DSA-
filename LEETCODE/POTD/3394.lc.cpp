#include <bits/stdc++.h>
using namespace std;

int merge(vector<pair<int , int>>& arr){
    vector<pair<int , int>> ans ;

    int s = arr[0].first , e = arr[0].second;

    ans.push_back({s , e});

    for( int i = 1 ; i < arr.size() ; ++i){
        pair<int , int> & last = ans.back();

        if(arr[i].first < last.second){
            last.second = max (last.second , arr[i].second);
        }else ans.push_back(arr[i]);
    }

    return ans.size();
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
 vector<pair<int , int>> X , Y;

 for(auto& co : rectangles){
    X.push_back({co[0] , co[2]});
    Y.push_back({co[1] , co[3]});
 }

 sort(begin(X) , end(X));
 sort(begin(Y) , end(Y));



 if(merge(X) >= 3) return true;
 if(merge(Y) >= 3) return true;

return false;

}


int main(){

    return 0;
}