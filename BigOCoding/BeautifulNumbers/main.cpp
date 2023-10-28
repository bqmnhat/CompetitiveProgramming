#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10
#define MaxM 100
using namespace std;
typedef long long ll;
int t;
ll dp[MaxM+1][(1 << MaxN) + 10][MaxN+1];
const ll Mod = 1e9 + 7;

void Solve() {
    for (int i = 1; i<=t; i++) {
        int n, m;
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<n; i++)
            dp[1][1 << i][i] = 1;
        for (int i=2; i<=m; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                for (int last = 0; last < n; last++) {
                    for (int nxt=last-1; nxt<=last+1; nxt += 2) {
                        if ((nxt < 0) || (nxt >= n))
                            continue;
                        dp[i][mask | (1 << nxt)][nxt] += dp[i-1][mask][last];
                        dp[i][mask | (1 << nxt)][nxt] %= Mod;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i=1; i<=m; i++)
            for (int last = 0; last < n; last++)
                ans = (ans + dp[i][(1 << n) - 1][last])%Mod;
        cout << ans << '\n';
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
