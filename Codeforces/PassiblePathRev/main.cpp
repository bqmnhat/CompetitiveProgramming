#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, q, tin[MaxN+1], tout[MaxN+1], counter = 0, parent[MaxN+1][20];
vector<int> g[MaxN+1];
pii p[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSPreprocess(int u, int p) {
    counter++;
    tin[u] = counter;
    parent[u][0] = p;
    for (int v: g[u]) {
        if (v == p)
            continue;
        DFSPreprocess(v, u);
    }
    counter++;
    tout[u] = counter;
}

void Preprocess() {
    counter = 0;
    DFSPreprocess(1, 1);
    int step, l = log2(n);
    for (int j=1; j <= l; j++)
        for (int i=1; i<=n; i++)
            parent[i][j] = parent[parent[i][j-1]][j-1];
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    int l = log2(n);
    for (int i=l; i>=0; i--)
        if (!IsAncestor(parent[u][i], v))
            u = parent[u][i];
    return parent[u][0];
}

void ReadSet(int k) {
    for (int i=1; i<=k; i++) {
        cin >> p[i].second;
        p[i].first = tin[p[i].second];
    }
}

void Solve() {
    Preprocess();
    int k;
    for (int i=1; i<=q; i++) {
        cin >> k;
        ReadSet(k);
        sort(p+1, p+1+k);
        int lca = p[1].second;
        for (int i=2; i<=k; i++)
            lca = LCA(lca, p[i].second);
        int ComeUpTop = 0;
        bool Check = true;
        for (int i=2; i<=k; i++) {
            int tmplca = LCA(p[i-1].second, p[i].second);
            if (tmplca == p[i-1].second)
                continue;
            if (tmplca == lca)
                ComeUpTop++;
            else {
                Check = false;
                break;
            }
        }
        if ((!Check) || (ComeUpTop > 1))
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
    ReadGraph();
    cin >> q;
    Solve();
    return 0;
}
