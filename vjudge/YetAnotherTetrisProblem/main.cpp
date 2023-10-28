#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n, a[MaxN+5];

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        bool Valid = true;
        for (int j=1; j<=n; j++) {
            cin >> a[j];
            if((j > 1) && ((a[j]&1) != (a[j-1]&1)))
                Valid = false;
        }
        if (Valid)
            cout << "YES\n";
        else
            cout << "NO\n";
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
