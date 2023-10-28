#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000001],k,l,m;

void MakeA() {
    a[1] = 1;
    a[k] = 1;
    a[l] = 1;
    for (int i=1; i<=1000000-min(l,k); i++) {
        if (a[i] == 0)
            a[i+1] = a[i+l] = a[i+k] = 1;
    }
}

void Solve() {
    int x;
    for (int i=1; i<=m; i++) {
        cin >> x;
        if (a[x] == 1)
            cout << 'A';
        else
            cout << 'B';
    }
}

int main()
{
    freopen("COINTOWER.INP", "r", stdin);
    freopen("COINTOWER.OUT", "w", stdout);
    cin >> k >> l >> m;
    MakeA();
    Solve();
    return 0;
}
