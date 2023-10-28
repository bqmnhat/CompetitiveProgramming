#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n, p[1001], w[1001], g, mw[101], dp[1001][31];

void InitDp() {
    for (int i=0; i<=n; i++)
        for (int j=0; j<=30; j++)
            dp[i][j] = 0;
}

void ReadData() {
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> p[i] >> w[i];
    cin >> g;
    for (int i=1; i<=g; i++)
        cin >> mw[i];
}

int Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j <= 30; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - w[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + p[i]);
        }
    }
    int ans = 0;
    for (int i=1; i<=g; i++)
        ans += dp[n][mw[i]];
    return ans;
}

void Solve() {
    for (int i=1; i<=T; i++) {
        ReadData();
        InitDp();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    return 0;
}
