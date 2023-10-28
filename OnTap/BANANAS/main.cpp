#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[201][201], b[201][201];

void Init() {
    for (int i=0; i<=200; i++) {
        for (int j=0; j<=200; j++) {
            b[i][j] = -2e9;
        }
    }
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=n+1; i<=2*n-1; i++) {
        for (int j=1; j<=2*n-i; j++) {
            cin >> a[i][j];
        }
    }
}

int MaxBanana() {
    b[1][1] = a[1][1];
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            b[i][j] = max(b[i-1][j], b[i-1][j-1]) + a[i][j];
        }
    }
    for (int i=n+1; i<=2*n-1; i++) {
        for (int j=1; j<=2*n-i; j++) {
            b[i][j] = max(b[i-1][j], b[i-1][j+1]) + a[i][j];
        }
    }
    return b[2*n-1][1];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        Init();
        ReadData();
        cout << MaxBanana() << endl;
    }
}

int main()
{
    freopen("BANANAS.INP", "r", stdin);
    freopen("BANANAS.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
