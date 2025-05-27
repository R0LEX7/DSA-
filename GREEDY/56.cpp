#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> a , vector<int> b) {
    return a[1] < b[1];
}

int help(vector < vector<int>> arr , int n ){

    sort(arr.begin() , arr.end() , compare);
    vector < vector<int>> ans;
        ans.push_back({arr[0][0] , arr[0][1]});

    int  et = arr[0][1] , cnt = 0;;

    for(int i = 1 ; i < n ; i++){
        if( et >= arr[i][0]){
            // overlapping found
            // set ending time of current to previous
            ans[i -1][1]  =  arr[i][1];
            cnt++;
        }
        else{
            ans.push_back({arr[i][0] , arr[i][1]});
         et = arr[i][1];
        }
    }

    return cnt;
}


int main(){
 vector < vector<int>> arr = {{1,2} , {2,3} , {3,5} , {5,7} , {4,5}};

    cout<<help(arr , arr.size())<<endl;
    return 0;
}
