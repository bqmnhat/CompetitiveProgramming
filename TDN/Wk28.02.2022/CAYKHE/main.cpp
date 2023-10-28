#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], b[101], dp[101][101], trace[101], lt = 0;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= b[i])
                dp[i][j] = max(dp[i][j], dp[i-1][j-b[i]] + a[i]);
        }
    }
    cout << dp[n][m] << '\n';
    int i = n, j = m;
    while ((i > 0) && (j > 0)) {
        if (dp[i][j] == dp[i-1][j-b[i]] + a[i]) {
            lt++;
            trace[lt] = i;
            j = j - b[i];
            i--;
        }
        else
            i--;
    }
    cout << lt << ' ';
    for (int i=lt; i>=1; i--)
        cout << trace[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAYKHE.INP", "r", stdin);
    freopen("CAYKHE.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
