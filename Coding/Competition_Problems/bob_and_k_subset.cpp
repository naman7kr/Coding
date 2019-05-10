#include <bits/stdc++.h>
using namespace std;

long long  modInverse(long long  a, long long m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

// Driver Program
int main()
{
    long long a = 6, m = 1000000007;
    cout << modInverse(a, m);
    return 0;
}