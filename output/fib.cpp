#include <iostream>
using namespace std;

int fib(int n)
{

    if (n <= 1)
    {
        return n;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    };
};

void fibonacci(int n){

    int first = 0;
    int second = 1;
    int third;

    cout<< first << endl;
    cout << second << endl;

    for (int i = 2; i <= n; i++)
    {
        third = first + second;
        cout << third << endl;
        first = second;
        second = third;
    }
    
}
int main()
{
    int n;
    cout << " enter your number: ";
    cin >> n;

    cout << " fibonacci series upto " << n << " is" << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << fib(i) << endl;
    // }

   fibonacci(n);


    return 0;
}