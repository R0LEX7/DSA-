#include <bits/stdc++.h>
using namespace std;

 int numberOfWeakCharacters(vector<vector<int>>& arr) {
    int n = arr.size() , mini = INT_MIN;


    sort(arr.begin() , arr.end() , [](vector <int> a , vector <int> b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    int cnt = 0;



    for(int i = n-1 ; i >= 0 ; i++){

        int val = arr[i][1];

        if(val < mini) cnt++;
        mini = max(mini , val);
    }

    return cnt;

    }


int main(){

    return 0;
}