#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m = {{1, "one"}, {2, "two"}};

    for (auto [key, val] : m) {
        cout << key << " -> " << val << endl;
    }
    cout<<"hello v20"<<endl;
    return 0;
}
