#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001], b[1001], n;

void ReadData() {
    for (int i=1; i<=2; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void Solve() {
    b[1] = (a[1][2] + a[1][3] - a[2][3])/2;
    cout << b[1] << " ";
    for (int i=2; i<=n; i++) {
        b[i] = a[1][i] - b[1];
        cout << b[i] << " ";
    }
}

int main()
{
    freopen("FINDARR.INP", "r", stdin);
    freopen("FINDARR.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
