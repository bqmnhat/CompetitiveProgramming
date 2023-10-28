#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001], A[5001], B[5001], m, n;

void ReadData() {
    cin >> m;
    for (int i=1; i<=m; i++)
        cin >> A[i];
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> B[i];
}

int Solution() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("32.INP", "r", stdin);
    freopen("32.OUT", "w", stdout);
    ReadData();
    cout << Solution();
    return 0;
}
