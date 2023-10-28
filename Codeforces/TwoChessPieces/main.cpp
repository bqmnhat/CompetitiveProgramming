#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
/*
    1. If one of the piece visit vertex u => They must visited vertex par[u]: either pieces start from the root (vertex 1) or from a root of a subtree
    2. If one of the piece visit vertex u, it go by 2 path:
        a. Going from u to it's descendants
        b. Going from u up to the root
    3. Each vertex just need to visit once

    Algorithm:
    - Call dp[x][u] = (vis[u] by x)? 1:0 as x representing one of the piece
    - From (1.) => dp[x][par] |= dp[x][u]
    - Considering the distance constrain: we will store the recently visited vertices in the DFS process since previous d units called Rec[]
    - dp[other piece][Rec[Rec.size() - d]] |= dp[x][u]
    - From (3.) and (2.) => ans = Sum(dp[piece 1][u] + dp[piece 2][u]) * 2 for every vertex u
*/
int n, d, m1, m2, dp[3][MaxN+5], a[MaxN+5], b[MaxN+5], Rec[MaxN+5], RecSize = 0;
vector<int> g[MaxN+5];

void ReadData() {
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> m1;
    for (int i=1; i<=m1; i++)
        cin >> a[i];
    cin >> m2;
    for (int i=1; i<=m2; i++)
        cin >> b[i];
}

void CalDp(int u, int p) {
    if (RecSize >= d) {
        dp[2][Rec[RecSize - d + 1]] |= dp[1][u];
        dp[1][Rec[RecSize - d + 1]] |= dp[2][u];
    }
    RecSize++;
    Rec[RecSize] = u;
    for (int v: g[u])
        if (v != p)
            CalDp(v, u);
    if (p != -1) {
        dp[1][p] |= dp[1][u];
        dp[2][p] |= dp[2][u];
    }
    RecSize--;
}

int Solution() {
    dp[1][1] = dp[2][1] = 1;
    for (int i=1; i<=m1; i++)
        dp[1][a[i]] = 1;
    for (int i=1; i<=m2; i++)
        dp[2][b[i]] = 1;
    int ans = 0;
    CalDp(1, -1);
    for (int i=2; i<=n; i++)
        ans += dp[1][i] + dp[2][i];
    return (ans << 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    ReadData();
    cout << Solution();
    return 0;
}
