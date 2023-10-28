#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, m, low[MaxN+1], num[MaxN+1], counter = 0, vert[MaxN+1], bridges = 0;
vector<int> g[MaxN+1], edges[MaxN+1];
bool vis[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

int DFSToCountBridges(int u, int p, ll &ans) {
    int Children = 0;
    counter++;
    low[u] = num[u] = counter;
    for (int v: g[u]) {
        if ((num[v]) && (v != p))
            low[u] = min(low[u], num[v]);
        else if (!num[v]) {
            int Children2 = DFSToCountBridges(v, u, ans);
            Children += Children2;
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                bridges++;
                ans += ((1LL*Children2*(1LL*n - 1LL*Children2)) - 1LL);
            }
        }
    }
    return Children + 1;
}

void DFSToCountCC(int u, int& ver) {
    vis[u] = true;
    ver++;
    for (int v: g[u])
        if (!vis[v])
            DFSToCountCC(v, ver);
}

ll Solution() {
    int CC = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            CC++;
            DFSToCountCC(i, vert[CC]);
        }
    }
    if (CC > 2)
        return 0LL;
    ll ans = 0;
    if (CC == 1) {
        DFSToCountBridges(1, -1, ans);
        ans += 1LL*(1LL*m - 1LL*bridges)*((1LL*n*1LL*(n-1LL)/2) - 1LL*m);
    }
    else {
        ll tmp = 0; // Bien nay dat de co du tham so cho ham DFSToCountBridges()
        for (int i=1; i<=n; i++)
            if (!num[i])
                DFSToCountBridges(i, -1, tmp);
        ans = 1LL*(1LL*m - 1LL*bridges)*1LL*vert[1]*1LL*(1LL*n - 1LL*vert[1]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    cout << Solution();
    return 0;
}
