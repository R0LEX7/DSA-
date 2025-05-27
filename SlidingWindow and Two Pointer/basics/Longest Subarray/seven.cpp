#include <bits/stdc++.h>
using namespace std;

int func(string str, int k) {
    int maxi = 0, l = 0, r = 0;
    int n = static_cast<int>(str.size()); // Cast to int
    unordered_map<char, int> map;

    while (r < n) {
        map[str[r]] = r;

        if (map.size() > k) {
            if (map[str[l]] == l) map.erase(str[l]);
            l++;
        } else {
            maxi = max(maxi, r - l + 1);
        }

        r++;
    }

    return map.size() < k ? -1 : maxi;
}

int main() {
    string str = "aabacbebebe";
    int k = 3;

    int ans = func(str, k);

    cout << ans << endl;

    return 0;
}
