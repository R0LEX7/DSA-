#include <iostream>

using namespace std ;
#include<bits/stdc++.h>
int main(){
    string s("cbacdcbc");
    for(int i = 0 ; i<s.length() ; i++){
        cout<<s[i]<<endl;
    }
    cout<<endl;
    std::cout << "Hello world!";
        cout<<endl;

    sort(s.begin(), s.end());
        for(int i = 0 ; i<s.length() ; i++){
        cout<<s[i]<<endl;
    }
    return 0;
}