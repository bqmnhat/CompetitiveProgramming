#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long dp[251][251], a[51], n,m;

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> a[i];
    }
}

void Solve() {
    sort(a+1,a+1+m);
    for (int i=1; i<=m; i++) {
        dp[0][i] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            long long x = 0,y = 0;
            if (i - a[j] >= 0)
                x = dp[i-a[j]][j];
            y = dp[i][j-1];
            dp[i][j] = x + y;
        }
    }
    cout << dp[n][m];
}

int main()
{
    freopen("COINCHANGE.INP", "r", stdin);
    freopen("COINCHANGE.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
