#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n, a[MaxN+1], XorAll = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        XorAll = XorAll ^ a[i];
    }
}

int Solution() {
    for (int i=1; i<=n; i++) {
        int XorAllTmp = 0;
        for (int j=1; j<=n; j++) {
            if (i == j)
                continue;
            XorAllTmp = XorAllTmp ^ a[j];
        }
        if (XorAll^a[i] == XorAllTmp)
            return a[i];
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        XorAll = 0;
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
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
