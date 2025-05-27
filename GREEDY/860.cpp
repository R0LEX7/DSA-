#include <bits/stdc++.h>
using namespace std;

bool help(vector<int> arr){
    int x=0,y=0;

    for(int n: arr){
        if(n == 5) x++;
        else if(n== 10){
            x--;
            y++;
        }
        else {
            if(y>0){
                y--;
                x--;
            }else{
              x = x-3;

            }
        }

    if(x < 0 || y < 0) return false;
    }

    return true;
}


int main(){

    vector <int> arr = {5,5,5,10,20};

    cout<<help(arr)<<endl;

    return 0;
}
