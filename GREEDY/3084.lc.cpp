#include <bits/stdc++.h>
using namespace std;


bool isValid(string s , char v){
    int n = s.size() -1;
    return s[0] == v && s[n] == v;

}

long long help (string s , char c) {
    int n = s.size();
    // string temp;
    int l = 0;

   long long cnt = 0;

    for (int i = 0; i < n; i++){
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];
            if(isValid(temp , c) ) cnt++;

        }
    }




    return cnt;
}


int main(){

    string s = "zzz";
    char c = 'z';

    int ans = help(s , c);

    cout<< ans <<endl;

    return 0;
}
