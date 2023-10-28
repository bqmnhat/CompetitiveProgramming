#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
#define MaxK 100
using namespace std;
typedef long long ll;
int t, n, k;
ll dp[MaxN+1][MaxK+1], dp2[MaxN+1][MaxK+1], a[MaxN+1];
vector<int> g[MaxN+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        g[i].clear();
    }
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void CalDp(int u, int p) {
    for (int v: g[u]) {
        if (v == p)
            continue;
        CalDp(v, u);
        for (int j=0; j<=k; j++) {
            if (j - a[u] >= 0)
                dp[u][j] = (dp[u][j] + dp[v][j - a[u]])%Mod;
            for (int x = 0; x<=j; x++)
                dp[u][j] = (dp[u][j] + (dp[v][x]*dp2[u][j - x])%Mod)%Mod;
        }
        for (int j=0; j<=k; j++)
            dp2[u][j] = dp[u][j];
    }
    dp[u][a[u]] = (dp[u][a[u]] + 1LL)%Mod;
}

ll Solution() {
    for (int i=0; i<=n; i++)
        for (int j=0; j<=k; j++)
            dp[i][j] = dp2[i][j] = 0;
    CalDp(1, -1);
    ll ans = 0;
    for (int i=1; i<=n; i++)
        ans = (ans + dp[i][k])%Mod;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
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
