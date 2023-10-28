#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool IsPrime(int n) {
    if (n==1)
        return false;
    if (n<=0)
        return false;
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    int d = 0;
    freopen("Sum_nt.inp", "r", stdin);
    freopen("Sum_nt.out", "w", stdout);
    for (int i = 2; i<=n; i++) {
        if (IsPrime(i)) {
            cout << i << " ";
            d = d + i;
        }
    }
    cout << d;
    return 0;
}
