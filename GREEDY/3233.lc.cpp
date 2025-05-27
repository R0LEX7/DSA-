#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int help(int l, int r)
{
    int n = sqrt(r); // We only need primes up to sqrt(r)
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Sieve of Eratosthenes to find all primes up to sqrt(r)
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int cnt = 0;

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i]){

            long long val = 1LL * i * i; // Calculate square of the prime
            if (val >= l && val <= r)
        {
            cnt++;
        }
        }

    }
    return r - (l + cnt) + 1;
}

int main()
{

    int ans = help(5, 7);

    cout << ans << endl;
    return 0;
}
