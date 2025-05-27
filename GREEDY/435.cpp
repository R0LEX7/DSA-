#include <bits/stdc++.h>
using namespace std;

static bool compare(vector<int> a , vector<int> b) {
    return a[0] < b[0];
}

int help(vector < vector<int>> arr , int n ){

    sort(arr.begin() , arr.end() , compare);

    int  et = arr[0][1] , cnt = 0;;

    for(int i = 1 ; i < n ; i++){
        if( et > arr[i][0]){
            cnt++;
        }
        else{
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
