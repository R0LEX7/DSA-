#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string smallestNumber(string pattern) {
        stack <char> st;
        string ans = "";
        char cnt = '1';

        for(int i= 0 ; i <= pattern.size() ; i++){
            char ch = pattern[i];
            if( i == pattern.size()) st.push(cnt++);
            else if(ch == 'D') st.push(cnt++);
            else{
                st.push(cnt++);
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
            }
        }

        if(!st.empty()){
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }
        }

        return ans;
    }


};

int main() {
    string ans = Solution().smallestNumber("IIIDIDDD");
    cout << ans << endl;  // Expected output: "123549876"

    return 0;
}
