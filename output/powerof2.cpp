#include<iostream>
using namespace std;

 bool isPowerTwo(int n){

    if (n==0) return false;

    if(n == 1){
        return true;
    }

    return (n%2 == 0 && isPowerTwo(n/2)); 
    // return ( n == 1 || (n%2 == 0) && (isPowerTwo(n/2)));

 }

     bool isPowerOfThree(int n) {
        if(n == 0){
          return false;
        };
        if(n == 1){
          return true;
        };

        return (n%3 == 0 && isPowerOfThree(n/3));

        
    }


int main()
{

    int num1 = 32;
    int num2 = 10;
    bool ans1 = isPowerTwo(num1);
    bool ans2 = isPowerOfThree(num2);
    cout << ans1 << endl;
    cout << ans2 << endl;



    return 0;
}