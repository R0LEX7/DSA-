#include<iostream>
using namespace std;

int sayDigit(int n , string arr[] ){

    if (n == 0){
        return 0;
    }

    int digit = n % 10;
    n = n / 10;
    sayDigit( n, arr );

    cout<< arr[digit] << " ";
}


int main()
{
    string arr[10] = {"zero" , "one" , "two" , "three" , "four" , "five", "six" , "seven" , "eight" , "nine"};

    int n ;
    cout << "Enter the number :";
    cin>>n;

    sayDigit(n,arr);



    return 0;
}