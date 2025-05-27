#include <bits/stdc++.h>
using namespace std;

long long help(vector<int> arrA , vector <int> arrB){
    long long sa = 0 , sb = 0 , za = 0 , zb = 0;

    for(int x : arrA){
        sa += max(x,1);
        za += x == 0;
    }

    for(int x : arrB){
        sb += max(x,1);
        zb += x == 0;
    }

    if((sa > sb && zb == 0)) return -1;
    if((sa < sb && za == 0)) return -1;

    return max(sa , sb);
}


int main(){

    vector <int> nums1 = {3,2,0,0,1} , nums2 = {6,5,0};

    long long ans = help(nums1 , nums2);

    cout<<ans<<endl;

    return 0;
}
