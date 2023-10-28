#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, dp[MaxN+5];
vector<int> g[MaxN+5];

void ReadData() {
    int v;
    for (int u=2; u<=n; u++) {
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p) {
    dp[u] = 1;
    for (int v: g[u]) {
        if (v != p) {
            DFS(v, u);
            dp[u] += dp[v];
        }
    }
}

void Solve() {
    DFS(1, -1);
    for (int i=1; i<=n; i++) {
        dp[i]--;
        cout << dp[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
