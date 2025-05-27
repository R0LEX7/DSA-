#include <bits/stdc++.h>
using namespace std;

void fun(string &word , int k){

    if(word.length() >=k) return;
    string temp = word;
    for(char ch : temp){
        word.push_back(ch +1);
    };

    fun(temp , k);

}


int main(){

    return 0;
}