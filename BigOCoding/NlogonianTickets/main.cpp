#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, q, l, spTMax[MaxN+1][20], parent[MaxN+1][20], tin[MaxN+1], tout[MaxN+1], counter = 0, log_2[MaxN+1];
vector<pii> graph[MaxN+1];

void ReadGraph() {
    for (int i=1; i<=n; i++)
        graph[i].clear();
    int u, v, w;
    for (int i=1; i<n; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(pii(v, w));
        graph[v].push_back(pii(u, w));
    }
}

void MakeLog2() {
    log_2[1] = 0;
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2] + 1;
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    parent[u][0] = p;
    for (auto tmpv: graph[u]) {
        int v = tmpv.first, w = tmpv.second;
        if (v != p) {
            spTMax[v][0] = w;
            DFS(v, u);
        }
    }
    counter++;
    tout[u] = counter;
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

void PreProcess() {
    counter = 0;
    l = log_2[n];
    DFS(1, 1);
    for (int k=1; k<=l; k++) {
        for (int i=1; i<=n; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            spTMax[i][k] = max(spTMax[i][k-1], spTMax[parent[i][k-1]][k-1]);
        }
    }
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    for (int k=l; k>=0; k--)
        if (!IsAncestor(parent[u][k], v))
            u = parent[u][k];
    return parent[u][0];
}

int MaxFromUToV(int u, int v) {
    int ans = 0;
    for (int k = l; k>=0; k--) {
        if (IsAncestor(v, parent[u][k])) {
            ans = max(ans, spTMax[u][k]);
            u = parent[u][k];
        }
    }
    return ans;
}

void SolveTestCase() {
    cin >> q;
    PreProcess();
    for (int i=1; i<=q; i++) {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        int ans = max(MaxFromUToV(u, lca), MaxFromUToV(v, lca));
        cout << ans << '\n';
    }
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadGraph();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeLog2();
    Solve();
    return 0;
}
