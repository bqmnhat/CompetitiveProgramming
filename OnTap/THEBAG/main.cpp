#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int w[1001], a[1001], f[1001][1001], n, m;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int j=1; j<=n; j++)
        cin >> w[j];

}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (w[i] <= j) {
                f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + a[i]);
            }
            else
                f[i][j] = f[i-1][j];
        }
    }
    cout << f[n][m];
}

int main()
{
    freopen("THEBAG.INP", "r", stdin);
    freopen("THEBAG.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
