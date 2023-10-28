#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, q, k, tin[MaxN+1], tout[MaxN+1], counter, par[MaxN+1][20];
vector<int> graph[MaxN+1];
pii p[MaxN+1];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    for (int v: graph[u])
        if (v != p)
            DFS(v, u);
    counter++;
    tout[u] = counter;
}

void ReadSet() {
    for (int i=1; i<=k; i++) {
        cin >> p[i].second;
        p[i].first = tin[p[i].second];
    }
}

void Preprocess() {
    counter = 0;
    int l = log2(n);
    DFS(1, 1);
    for (int k=1; k<=l; k++)
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
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
    for (int k=l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

void Solve() {
    Preprocess();
    for (int i=1; i<=q; i++) {
        cin >> k;
        ReadSet();
        sort(p+1, p+1+k);
        int lca = p[1].second;
        for (int i=2; i<=k; i++)
            lca = LCA(lca, p[i].second);
        int cntRev = 0;
        bool Check = true;
        for (int i=1; i<k; i++) {
            int tmplca = LCA(p[i].second, p[i+1].second);
            if (tmplca != p[i].second) {
                if (tmplca == lca)
                    cntRev++;
                else {
                    Check = false;
                    break;
                }
            }
        }
        if ((cntRev > 1) || (!Check))
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
