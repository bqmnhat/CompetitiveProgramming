#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int m, n, q;
const ll INF = 1e13;
ll c[MaxN+5][MaxN+5], dp[MaxN+5][MaxN+5][2]; // [0] means last char is from X, [1] means last char is from Y

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> c[i][j];
}

ll Solution() {
    dp[0][0][0] = dp[0][0][1] = INF;
    for (int i=1; i<=n; i++) {
        dp[0][i][0] = INF;
        dp[0][i][1] = 0;
    }
    for (int i=1; i<=m; i++) {
        dp[i][0][1] = INF;
        dp[i][0][0] = 0;
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j][0] = dp[i][j][1] = INF;
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + c[i][j]);
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]);
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][0] + c[i-1][j] + c[i][j]);

            dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0] + c[i][j]);
            dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-1][1] + c[i][j-1] + c[i][j]);
            dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]);
        }
    }
    ll ans = min(dp[m][n][0], dp[m][n][1]);
    return ans;
}

void Solve() {
    for (int i=1; i<=q; i++) {
        memset(dp, 0, sizeof(dp));
        cin >> m >> n;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    Solve();
    return 0;
}
