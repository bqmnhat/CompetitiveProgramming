#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int Solution() {
    if (n == 1)
        return 1;
    int m = sqrt(n), d, i = 2, p = 1;
    while ((i<=m) && (n>1)) {
        d = 0;
        if (n%i == 0)
            p = p*(-1);
        while (n%i == 0) {
            d++;
            n = n/i;
            if (d > 1)
                return 0;
        }
        i++;
    }
    if (n>1) {
        p = p*(-1);
    }
    return p;
}

int main()
{
    freopen("MOBIUS.INP", "r", stdin);
    freopen("MOBIUS.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}

