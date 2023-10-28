#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

bool IsPrime(int x) {
    int m = sqrt(x);
    if (n <= 1)
        return false;
    for (int i = 2; i<=m; i++) {
        if (x%i==0)
            return false;
    }
    return true;
}

bool IsSupPri(int n) {
    while (n>0) {
        if (IsPrime(n) == false)
            return false;
        n = n/10;
    }
    return true;
}

int main()
{
    freopen("SUPPRI.INP", "r", stdin);
    freopen("SUPPRI.OUT", "w", stdout);
    cin >> n;
    if (IsSupPri(n))
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}
