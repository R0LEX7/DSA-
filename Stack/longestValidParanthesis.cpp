#include<iostream>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
    // Write your code here.
    int n = s.length();
    int count = 0;
    stack <char> st;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        // if opening parentheses push to stack;
        if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else{
                st.push(ch);
            }
        }
    };

    return n-st.size();
    
}


int main(){

    string str = "()((())()";
    cout<<"longest valid parenthesis -> "<<longestValidParentheses(str)<<endl;

    return 0;
}