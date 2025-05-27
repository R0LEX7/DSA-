#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s) {
      stack<char> st;

      for(char ch : s){
        if(ch >= 'a' && ch <= 'z') st.push(ch);
        else st.pop();
      }

      string ans;
      int i = st.size();
      while(!st.empty()){
        ans += st.top();
        st.pop();
      }

      return ans;
}


int main(){

    string ans = clearDigits("cb34");
    for(char c : ans){
        cout<<c<<endl;
    }

    return 0;
}
