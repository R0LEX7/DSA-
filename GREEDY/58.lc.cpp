#include <bits/stdc++.h>
using namespace std;

int help(string s)
{
    int n = s.size(), cnt = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != ' '){
            int j = i;
            while(s[j] != ' '){
                cnt++;
                j--;
            }
            break;
        }
    }

    return cnt;
}

int main()
{

    string s = "luffy is still joyboy";
    int ans = help(s);

    cout<<ans;

    return 0;
}
