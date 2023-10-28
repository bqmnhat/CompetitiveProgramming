#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1001][1001],b[1001][1001], m,n;

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

long long Solution() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] % 2 == 0) {
                b[i][j] = max(b[i-1][j], b[i][j-1]) + a[i][j];
            }
            else {
                b[i][j] = max(b[i-1][j], b[i][j-1]);
            }
        }
    }
    return b[m][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXSUM.INP", "r", stdin);
    freopen("MAXSUM.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
