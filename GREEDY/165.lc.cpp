#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
    int n1 = version1.length() , n2 = version2.length() , v1 = 0 , v2 = 0;

    for(int i = n1-1 ; i >=0 ; i--){
        if(version1[i] != '.' || version1[i] != '0'){
            v1 = v1 * 10 + version1[i] - '0';
        }
    }

    for(int i = n2-1 ; i >=0 ; i--){
        if(version2[i] != '.' || version2[i] != '0'){
            v2 = v2 * 10 + version2[i] - '0';
        }
    }

    if(v1 == v2) return 0;

    return v1 > v2 ? 1 : -1;
}


int main(){
    return 0;
}