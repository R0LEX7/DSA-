#include <bits/stdc++.h>
using namespace std;

int qs(vector<int> &arr , int low , int high){
    int pivot = arr[low];
    int i = low , j = high;

    while(i < j){

            while( arr[i] <= pivot  && i <= high){
                i++;
            }
            while( arr[j] > pivot  && j >= low){
                j--;
            }

            if(i < j) swap(arr[i] , arr[j]);



    }
        swap(arr[low] , arr[j]);

        return j;
}


void f(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = qs(arr, low, high);
        f(arr, low, pIndex - 1);
        f(arr, pIndex + 1, high);
    }
}




int main(){

    vector<int> arr = {4,10,3,7,8,11,2,3};

    f(arr , 0 , arr.size() -1);

    cout << "Sorted array: ";
    for (const int &num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
