#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n;
ll dp[MaxN+1][2]; // dp[i][0/1] = num of ways to color i white/black
vector<int> g[MaxN+1];
const ll Mod = 1e9 + 7;

void ReadGraph() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if ((dp[v][0] == 0) && (dp[v][1] == 0))
            DFS(v, u);
        dp[u][0] = (dp[u][0]*(dp[v][0] + dp[v][1]))%Mod;
        dp[u][1] = (dp[u][1]*dp[v][0])%Mod;
    }
}

ll Solution() {
    for (int i=2; i<=n; i++)
        if (g[i].size() == 1)
            dp[i][0] = dp[i][1] = 1;
    DFS(1, 0);
    ll ans = (dp[1][0] + dp[1][1])%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadGraph();
    cout << Solution();
    return 0;
}
