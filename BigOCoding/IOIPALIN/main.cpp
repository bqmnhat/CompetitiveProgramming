#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, dp[5001][5001];
string s;

int Solution() {
    string t = s;
    reverse(t.begin(), t.end());
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
        }
    }
    return (n - dp[n][n]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << Solution();
    return 0;
}
