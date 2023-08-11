#include <iostream>
using namespace std;

void pattern(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
};

void leftTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >0; j--)
        {
            cout << " " ;
        };
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        };

        
        cout << "\n";
        
    };
    

};

void swapXor(int x, int y)
{
    cout << x << ", " << y << endl;

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout << x << ", " << y << endl;
}

int main()
{
    int n;
    cout << "enter number of rows" << endl;
    cin >> n;

    // pattern(n);

    // swapXor(25, 30);

    leftTriangle(n);

    return 0;
}