#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001], b[1001], dp[1001][1001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int j=1; j<=m; j++)
        cin >> b[j];
}

int Solution() {
    for (int i=1; i<=m; i++) {
        dp[1][i] = dp[1][i-1];
        if (a[1] == b[i])
            dp[1][i] = 1;
    }
    for (int i=1; i<=n; i++) {
        dp[i][1] = dp[i-1][1];
        if (a[i] == b[1])
            dp[i][1] = 1;
    }
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i-2][j-2] + 1);
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
