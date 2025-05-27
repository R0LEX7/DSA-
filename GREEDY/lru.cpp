#include <bits/stdc++.h>
using namespace std;

int getLRU(vector <int> arr ,int c){
    int n = arr.size() , pageFault = 0;;

    unordered_set <int> cap ;
    unordered_map <int , int> map;


    for(int i = 0 ; i < n ; i++){
        // if nahi mila memory me
    if(cap.find(arr[i]) == cap.end()){
       if(cap.size() == c){
            int lru = INT_MAX , val;

            // find the least used
            for(int x : cap){
                if(map[x] < lru){
                    lru = map[x]; // lru will be index
                    val = x; // least used value
                }
            }

            cap.erase(val); // erase the lru from memory
        }
            cap.insert(arr[i]);
            pageFault++;
    }
        map[arr[i]] = i;
       }

    return pageFault;
}


int main(){

    vector<int> pages = {7, 7, 7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout << getLRU(pages, capacity);

    return 0;
}
