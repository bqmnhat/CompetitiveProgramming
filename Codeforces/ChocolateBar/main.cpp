#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30
#define MaxK 50
using namespace std;
typedef long long ll;
int t, n, m, k;
ll dp[MaxN+1][MaxN+1][MaxK+1];
const ll INF = 1e18;

void Init() {
    for (int i=1; i<=MaxN; i++) {
        for (int j=1; j<=MaxN; j++) {
            for (int t=0; t<=MaxK; t++) {
                if (t == 0)
                    dp[i][j][t] = 0;
                else
                    dp[i][j][t] = 1e18;
            }
        }
    }
}

void DpCal(int n, int m, int k) {
    dp[n][m][k] = INF + 1LL;
    if (n*m == k) {
        dp[n][m][k] = 0;
        return;
    }
    if (k > n*m)
        return;
    for (int t=1; t<n; t++) {
        for (int tmpk=0; tmpk<=k; tmpk++) {
            if (dp[n-t][m][k-tmpk] == INF)
                DpCal(n-t, m, k - tmpk);
            if (dp[t][m][tmpk] == INF)
                DpCal(t, m, tmpk);
            dp[n][m][k] = min(dp[n][m][k], dp[n - t][m][k-tmpk] + dp[t][m][tmpk] + m*m);
        }
    }
    for (int t=1; t<m; t++) {
        for (int tmpk=0; tmpk<=k; tmpk++) {
            if (dp[n][m-t][k-tmpk] == INF)
                DpCal(n, m-t, k - tmpk);
            if (dp[n][t][tmpk] == INF)
                DpCal(n, t, tmpk);
            dp[n][m][k] = min(dp[n][m][k], dp[n][m-t][k - tmpk] + dp[n][t][tmpk] + n*n);
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> k;
        if (dp[n][m][k] == INF)
            DpCal(n, m, k);
        cout << dp[n][m][k] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Init();
    Solve();
    return 0;
}
