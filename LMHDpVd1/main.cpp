#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, dp[101][101];

int Solution() {
    for (int i=0; i<=n; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= i)
                dp[i][j] += dp[i][j-i];
        }
    }
    return dp[n][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LMHDpVd1.INP", "r", stdin);
    freopen("LMHDpVd1.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
