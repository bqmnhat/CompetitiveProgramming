#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1002][1002], s[1002][1002];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

int MaxPath() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            s[i][j] = max(s[i-1][j], s[i][j-1]) + a[i][j];
        }
    }
    return s[n][n];
}

int main()
{
    freopen("MAXPATH.INP", "r", stdin);
    freopen("MAXPATH.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MaxPath();
    return 0;
}
