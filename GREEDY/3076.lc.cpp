#include <bits/stdc++.h>
using namespace std;

vector <string> generateSubstrings (string s) {
    int n = s.size();
    // string temp;

    vector <string> subs ;

    for (int i = 0; i < n; i++){
        string temp = "";
        for (int j = i; j < n; j++) {
            temp += s[j];
           subs.push_back(temp);
        }
    }

    sort(subs.begin() , subs.end() , [](const string& a , const string& b ){
        return a.size()< b.size() || a.size() == b.size() && a < b;
    });
    return subs;
}

vector <string> help(vector <string> arr){

    int n = arr.size();
    vector <string > ans(n);

    for (int i = 0; i < n; i++)
    {
        vector <string> subs = generateSubstrings(arr[i]);

        for ( auto& sub : subs){
            int unique = 1;
            for (int j = 0; j< n; j++)
            {
                if(i != j && arr[j].find(sub) != string::npos){
                    unique = 0;
                    break;
                }
            }

            if(unique){
                ans[i] = sub;
                break;
            }
        }

    }
    return ans;

}


int main(){

     vector <string> arr = {"cab" , "ad", "bad" , "c"};
    vector <string> ans = help(arr);

    // Print substrings
    for (const string& sub : ans) {
        cout << "{" << sub << "}" << endl;
    }

    cout<<ans.size() <<endl;

    return 0;
}
