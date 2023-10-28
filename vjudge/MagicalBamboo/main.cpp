#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool Check() {
    bool Even = false, Odd = false;
    for (int i=1; i<=n; i++) {
        if (a[i]&1)
            Odd = true;
        else
            Even = true;
        if (Odd == Even)
            return false;
    }
    return true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        if (Check())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
