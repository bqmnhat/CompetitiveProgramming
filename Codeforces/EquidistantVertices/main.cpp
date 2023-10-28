#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
typedef long long ll;
int t, n, k;
ll dp[MaxN+1][MaxN+1][MaxN+1], Layer[MaxN+1][MaxN+1][MaxN+1]; //Layer[root][which layer][which subtree]
vector<int> g[MaxN+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    int u, v;
    for (int i=1; i<=n; i++)
        g[i].clear();
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p, int root, int SubTreeId, int h) {
    Layer[root][h][SubTreeId]++;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFS(v, u, root, SubTreeId, h+1);
    }
}

void CountVerticesForAllLayers() {
    for (int i=1; i<=n; i++) {
        int cnt = 0;
        for(int u: g[i]) {
            cnt++;
            DFS(u, i, i, cnt, 1);
        }
    }
}

ll Solution() {
    ll ans = 0;
    for (int d = 1; d<=n; d++) {
        memset(dp, 0, sizeof(dp));
        for (int u = 1; u<=n; u++) {
            for (int i=0; i<=g[u].size(); i++)
                dp[u][i][0] = 1;
            for (int i=1; i<=g[u].size(); i++)
                for (int j=1; j<=k; j++)
                    dp[u][i][j] += ((Layer[u][d][i]*dp[u][i-1][j-1])%Mod + dp[u][i-1][j])%Mod;
            ans += dp[u][g[u].size()][k];
            ans %= Mod;
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        if (k == 2) {
            ll ans = (n*(n-1)/2)%Mod;
            cout << ans << '\n';
            continue;
        }
        memset(Layer, 0, sizeof(Layer));
        CountVerticesForAllLayers();
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
