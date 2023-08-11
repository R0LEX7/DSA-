#include <iostream>
using namespace std;

bool isSubsequence(string s, string t)
{

    int i = 0, j = 0;
    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return i == s.length();
}

int main()
{
    string s = "abc", t = "ahbgdc";
    bool ans = isSubsequence(s, t);
    cout << ans << endl;

    return 0;
}