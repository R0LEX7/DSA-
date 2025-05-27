#include <bits/stdc++.h>
using namespace std;


    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

     if(sx == fx && sy == fy){
        return t != 0;
     }

     int d = (sx - fx)*(sx - fx)  + (sy-fy)*(sy-fy);

  int timeTaken = pow(d , 0.5);

  return timeTaken <= t;
    }

int main(){

    return 0;
}