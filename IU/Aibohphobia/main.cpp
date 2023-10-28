#include <iostream>
#define MaxN 6100
using namespace std;
int t, n, dp[MaxN+2][MaxN+2];
string s;

int Solution() {
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 1e9;
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=n; j++) {
            if (i >= j)
                dp[i][j] = 0;
            else {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i+1][j-1] + 2, min(dp[i+1][j] + 1, dp[i][j-1] + 1));
            }
        }
    }
    return dp[1][n];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        s = ' ' + s;
        n = s.length();
        n--;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
