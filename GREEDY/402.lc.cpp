#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string s, int k)
{
    int n = s.length();
    if (n <= k)
        return "0";

    if (k == 0)
        return s;

    string st = "";
    st.push_back(s[0]);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and st.back() > s[i] and k > 0)
        {
            st.pop_back();
            k--;
        }
        st.push_back(s[i])
    }

    while (k-- > 0 && !st.empty())
        st.pop_back();

    int i = 0;
    while (i < st.size() && st[i] == '0')
        i++;


    string res = st.substr(i);
    return res.empty() ? "0" : res;
}

int main()
{

    return 0;
}
