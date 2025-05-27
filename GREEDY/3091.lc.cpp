#include <bits/stdc++.h>
using namespace std;

int help ( int key){
    int temp = key , op = 0;

    int val = ceil(sqrt(key));
    op = val-1;

    while(temp > val ){
        val = val * 2;
        op++;
    }
    return op;

}


int main(){

    cout << help(8)<<endl;

    return 0;
}
