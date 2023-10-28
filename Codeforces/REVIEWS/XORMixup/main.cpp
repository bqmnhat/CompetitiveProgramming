#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int n, t, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    for (int i=1; i<=n; i++) {
        int TmpXorAll = 0;
        for (int j=1; j<=n; j++) {
            if (i == j)
                continue;
            TmpXorAll ^= a[j];
        }
        if (TmpXorAll == a[i])
            return a[i];
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
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
