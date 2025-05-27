#include <bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       int n = A.size() , cnt = 0;

       vector<int> seen(34 , 0);
       vector<int> ans;

       for(int i = 0 ; i < n ; i++){
        if(seen[A[i]]){
            cnt++;
        }else seen[A[i]] = 1;

        if(seen[B[i]]){
            cnt++;
        }else seen[B[i]] = 1;

        ans.push_back(cnt);
       }
       return ans;
    }


int main(){

    return 0;
}
