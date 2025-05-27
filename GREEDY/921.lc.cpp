#include <bits/stdc++.h>
using namespace std;

    int minAddToMakeValid(string s) {
        int n = 0 ;
        char ch = '(';

        stack<char> st;

        for(char c : s){
            if(c == ch){
                st.push(c);
            }else{
                if(!st.empty() && st.top() == ch)st.pop();
                else {st.push(c);
                n++;
                }
            }
        }

        return n+ st.size();
    }


int main(){

    return 0;
}