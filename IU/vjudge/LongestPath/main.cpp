#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int dp[MaxN+1], n, m;
vector<int> g[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i = 1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        dp[i] = -1;
}

int DFS(int u) {
    int ans = 0;
    for (auto v: g[u]) {
        if (dp[v] != -1)
            ans = max(ans, dp[v] + 1);
        else
            ans = max(ans, DFS(v) + 1);
    }
    return (dp[u] = ans);
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (dp[i] != -1)
            ans = max(ans, dp[i]);
        else
            ans = max(ans, DFS(i));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Init();
    ReadGraph();
    cout << Solution();
    return 0;
}
