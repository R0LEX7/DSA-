#include <bits/stdc++.h>
using namespace std;

long long help(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long long t = 0, wt = 0 , n = arr.size(); // Use long long for cumulative variables

    for (int i = 0; i < n - 1; i++) { // Exclude the last element
        t += arr[i]; // Update cumulative time
        wt += t;     // Add to total waiting time
    }

    return wt/n;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    cout << help(arr) << endl; // Output: 10
    return 0;
}
