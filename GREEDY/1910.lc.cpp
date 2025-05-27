#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
        string ans = "";
        int n = s.size() , m = part.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == part[m-1]){
                int j = m-2 , k = ans.length()-1;
                while(!ans.empty() && ans[k] == part[j]){
                    j--;
                    k--;
                }
                if(j == -1){
                    for(j = 0 ; j < m-1 ; j++) ans.pop_back();
                }else ans.push_back(s[i]);
            }else ans.push_back(s[i]);
        }
            return ans;

}


int main(){

    string ans = removeOccurrences("axxxxyyyyb" , "xy");
    cout<<ans<<endl;

    return 0;
}
