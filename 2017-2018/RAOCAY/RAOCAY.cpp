#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n, a[1001][1001], OneNear[1001][1001], ans = 0;

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            if ((a[i][j-1] == 1) && (a[i][j] == 1)) {
                OneNear[i][j]++;
                OneNear[i][j-1]++;
            }
            if ((a[i-1][j] == 1) && (a[i][j] == 1)) {
                OneNear[i][j]++;
                OneNear[i-1][j]++;
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] == 1)
                ans = ans + 4 - OneNear[i][j];
        }
    }
    cout << ans;
}

int main()
{
    freopen("RAOCAY.INP", "r", stdin);
    freopen("RAOCAY.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
