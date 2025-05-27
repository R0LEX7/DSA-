#include <bits/stdc++.h>
using namespace std;

static bool compare (vector<int> a , vector <int> b){
    return a[0] < b [0];
}

int help(vector<int> arr, vector<int> dep){
    vector <vector<int>> train ;
    int n = arr.size();
    //  make a array of arrival and dep time
    for(int i = 0 ; i < n ; i++){
        vector<int> temp;
        temp.push_back(arr[i]);
        temp.push_back(dep[i]);
        train.push_back(temp);
    }

    // sort the array acc to arr time
    sort(train.begin() , train.end() , compare);

    int platform = 1;
    for(int i = 1 ; i < n ; i++){
        int lastDepTime = train[i-1][1];

        if(lastDepTime >= train[i][0]){
            platform++;
        }

    }

    return platform;


}


int main(){

    vector <int> arr = {900, 940, 950, 1100, 1500, 1800}, dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<help(arr , dep)<<endl;

    return 0;
}
