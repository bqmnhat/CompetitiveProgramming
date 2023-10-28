#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
#define MaxK 500
using namespace std;
typedef long long ll;
ll dp[MaxN+1][MaxK+1];
int n, k;
vector<int> g[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p, ll& ans) {
    dp[u][0] = 1;
    ll tmpans = 0;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFS(v, u, ans);
        for (int d=1; d<=k; d++)
            dp[u][d] += dp[v][d-1];
    }
    for (int v: g[u]) {
        if (v == p)
            continue;
        for (int d=1; d<k; d++)
            tmpans += dp[v][d-1]*(dp[u][k - d] - dp[v][k-d-1]); // Pair of vertices from different branches from u
    }
    ans += (tmpans >> 1LL);
}

ll Solution() {
    ll ans = 0;
    DFS(1, -1, ans);
    for (int i=1; i<=n; i++)
        ans += dp[i][k];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadGraph();
    cout << Solution();
    return 0;
}
