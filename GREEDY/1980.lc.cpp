#include <bits/stdc++.h>
using namespace std;

string findDifferentBinaryString(vector<string>& arr) {
    string ans = "";
    for(int i = 0 ; i < arr.size() ; i++){
        ans += arr[i][i] == '0'? '1' : '0';
    }
    return ans;
}


int main(){

    return 0;
}
