#include <bits/stdc++.h>
using namespace std;

int help (vector <int> arr) {

    int sum = 0;

    for (int num : arr){

        int maxi = INT_MIN;
        int cnt = 0;
        while (num >0){
            int digit = num % 10;
            num = num / 10;
            maxi = max(maxi , digit);
            cnt ++;
        }

        int newNum = 0;

       for(int i = 0 ; i < cnt ; i++){
       newNum = newNum * 10 + maxi;
       }
        cout << "Original: " << num << ", NewNum: " << newNum << endl;
        sum += newNum;

    }

    return sum;
}


int main(){

    vector<int> arr = {11,12,13};

    cout<<help(arr)<<endl;

    return 0;
}
