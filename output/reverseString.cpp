#include <iostream>
using namespace std;

string reverseString(string str, int size, int i)
{

    if (size / 2 <= i)
    {
        return str;
    }
    swap(str[i], str[size - 1 - i]);
    return reverseString(str, size, i + 1);
}

int main()
{
    string str;
    cout << "Enter String" << endl;
    cin >> str;
    cout << "Input String" << endl;
    cout << str << endl;
    int size = str.size();

    string reverse = reverseString(str, size, 0);
    cout << "Reversed String" << endl;
    cout << reverse << endl;

    return 0;
}