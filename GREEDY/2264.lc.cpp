#include <bits/stdc++.h>
using namespace std;

string largestGoodInteger(string num)
{
    int n = num.size() , max = -1;
    string ans ;

    unordered_map<string, int> map;

    map["999"] = 9;
    map["888"] = 8;
    map["777"] = 7;
    map["666"] = 6;
    map["555"] = 5;
    map["444"] = 4;
    map["333"] = 3;
    map["222"] = 2;
    map["111"] = 1;
    map["000"] = 0;

    for (auto [key, value] : map)
    {
        if (num.find(key) != std::string::npos){
            if (max < value) {
                max = value;
                ans = key;
            }
        }

    }

    return ans;
}

int main()
{

    return 0;
}