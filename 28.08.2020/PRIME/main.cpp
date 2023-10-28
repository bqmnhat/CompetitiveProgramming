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
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);
    cin >> n;
    if (IsPrime(n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
