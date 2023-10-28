#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, w[101], v[101], dp[101][201];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i] >> v[i];
}

void PrintAns() {
    int i = n, j = m;
    cout << dp[n][m] << '\n';
    while (i != 0) {
        if (dp[i][j] == dp[i-1][j])
            i--;
        else {
            cout << i << ' ';
            j = j - w[i];
            i--;
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (w[i] <= j)
                dp[i][j] = dp[i-1][j-w[i]] + v[i];
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAG.INP", "r" , stdin);
    freopen("BAG.OUT", "w" , stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
