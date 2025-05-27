#include <bits/stdc++.h>
using namespace std;

int getDigitSum (int n){

    int sum = 0;

    while(n != 0){
        sum += n%10;
        n = n/10;
    }

    return sum;
}

int maximumSum(vector<int>& arr) {

    unordered_map<int , pair<int ,int>> map;
    int  maxi = INT_MIN;

    for(int n : arr){
        int sum = getDigitSum(n);
        if(map.find(sum) != map.end()){
            if(map[sum].first > n){
                map[sum].second = max(map[sum].second , n);
            }else{
                map[sum].second = map[sum].first;
                map[sum].first = n;
            }
            maxi = max(map[sum].first + map[sum].second , maxi);
        }else {

            map[sum].first = n;
            map[sum].second = -1;
        }
    }

    return maxi;

}


int main(){

    return 0;
}
