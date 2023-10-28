#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,dp[20001][20001];
string s, t;

int Solution() {
    int ans = 0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if ((i == 0) || (j == 0)) {
                dp[i][j] = 0;
                continue;
            }
            if (s[i] == t[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PLAGIARISM.INP", "r", stdin);
    freopen("PLAGIARISM.OUT", "w", stdout);
    cin >> n >> m >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    cout << Solution();
    return 0;
}
