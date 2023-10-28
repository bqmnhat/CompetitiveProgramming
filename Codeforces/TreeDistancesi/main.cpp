#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, dp[MaxN+1][2], ans[MaxN+1];
vector<int> g[MaxN+1];
vector<pii> d[MaxN+1];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSDpDown(int u, int p) {
    dp[u][0] = 0;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFSDpDown(v, u);
        d[u].push_back(pii(dp[v][0], v));
    }
    if (d[u].size() > 0) {
        sort(d[u].begin(), d[u].end(), greater<pii>());
        dp[u][0] = d[u][0].first+1;
    }
}

void DFSDpUp(int u, int p) {
    dp[u][1] = 0;
    if (p != -1) {
        dp[u][1] = dp[p][1] + 1;
        if (d[p].size() > 0) {
            if (u != d[p][0].second)
                dp[u][1] = max(dp[u][1], d[p][0].first + 2);
            else if (d[p].size() >= 2)
                dp[u][1] = max(dp[u][1], d[p][1].first + 2);
        }
    }
    ans[u] = max(dp[u][0], dp[u][1]);
    for (int v: g[u])
        if (v!=p)
            DFSDpUp(v, u);
}

void Solve() {
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    DFSDpDown(1, -1);
    DFSDpUp(1, -1);
    Solve();
    return 0;
}
