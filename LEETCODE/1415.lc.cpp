#include <bits/stdc++.h>
using namespace std;

bool backtracking(int n , int k , string &ans, string &current , int &count){
    // base case
    if(current.size() == n){
        count++;
        if(count == k){
            ans = current;
            return true;
        }
        return false;
    }

    for(char ch = 'a' ; ch <= 'c' ; ch++){
        if(!current.empty() && current.back() == ch) continue;

        current.push_back(ch);
        if (backtracking(n , k , ans ,current ,  count)) return true;
        current.pop_back();
    }
    return false;
}

string getHappyString(int n, int k) {

     string ans = "" , current = "";
     int count = 0;
     backtracking(n, k, ans, current, count);
     return ans;
}


int main(){
    string ans = getHappyString(3, 9);
    cout<<ans<<endl;
    return 0;
}
