#include <bits/stdc++.h>
using namespace std;

int help(vector <int> arr){
    int n = arr.size() , cnt = 0;
    unordered_map <int , int> map;
    for(int x:arr) map[x]++;

    for(auto& [key , value] : map){
        if(value == 1) return -1;
        else if(value == 2) cnt++;
        else if(value == 3) cnt++;
        else {
            cnt += ((value + 2) / 3);
        }
    }

    return cnt;
}


int main(){

    return 0;
}
