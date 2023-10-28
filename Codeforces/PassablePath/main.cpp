#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, q, k, dp[MaxN+1];
vector<int> graph[MaxN+1];
int p[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        graph[i].clear();
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void ReadSet() {
    for (int i=1; i<=k; i++)
        cin >> p[i];
}

void DFS(int u, int p) {
    int br = 0;
    for (int v: graph[u]) {
        if (v != p) {
            DFS(v, u);
            if (dp[v] > 1)
                br += dp[v] + 1;
            else
                br += dp[v];
        }
    }
    dp[u] = max(dp[u], br);
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> k;
        ReadSet();
        for (int i=1; i<=n; i++)
            dp[i] = 0;
        for (int i=1; i<=k; i++)
            dp[p[i]] = 1;
        DFS(p[1], p[1]);
        if (dp[p[1]] > 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> q;
    Solve();
    return 0;
}
