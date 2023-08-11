#include<iostream>
using namespace std;

int arraySum(int arr[] , int sum , int size){

    if( size == 0){
        return sum;
    }else {
        sum += arr[0];
    }

    return arraySum(arr + 1,sum , size - 1);

}


int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int sum = 0;
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = arraySum(arr,sum , n);
    cout << ans << endl;

    return 0;
}