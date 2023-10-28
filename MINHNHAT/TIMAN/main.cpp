#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int FoundAN(int n) {
    if (n == 1) {
        return 3;
    }
    if (n == 2) {
        return 8;
    }
    return 3 + 5*(n-1) + 2*(2*n - 5);
}

int main()
{
    freopen("TIMAN.INP", "r", stdin);
    freopen("TIMAN.OUT", "w", stdout);
    cin >> n;
    cout << FoundAN(n);
    return 0;
}
