#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
int n, q, par[MaxN+1][21], tin[MaxN+1], tout[MaxN+1], counter = 0, l, height[MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSPreprocess(int u, int p, int h) {
    counter++;
    tin[u] = counter;
    height[u] = h;
    par[u][0] = p;
    for (int v: g[u])
        if (v != p)
            DFSPreprocess(v, u, h+1);
    counter++;
    tout[u] = counter;
}

void Preprocess() {
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    DFSPreprocess(1, 1, 0);
    l = ceil(log2(n));
    for (int j=1; j<=l; j++)
        for (int i=1; i<=n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v))
        return u;
    if (IsAncestor(v, u))
        return v;
    for (int k=l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

int BinaryLiftingUp(int u, int dist) {
    int cnt = 0;
    for (int k=l; k>=0; k--) {
        if (cnt + (1 << k) < dist) {
            u = par[u][k];
            cnt += (1 << k);
        }
    }
    return par[u][0];
}

int Solution(int a, int b, int c) {
    int lcaAB = LCA(a, b);
    int LCAToA = abs(height[a] - height[lcaAB]);
    int LCAToB = abs(height[b] - height[lcaAB]);
    if (c == LCAToA)
        return lcaAB;
    else if (c < LCAToA)
        return BinaryLiftingUp(a, c);
    else {
        c -= LCAToA;
        if (c >= LCAToB)
            return b;
        int DistUpFromB = LCAToB - c;
        return BinaryLiftingUp(b, DistUpFromB);
    }
}

void Solve() {
    Preprocess();
    for (int i=1; i<=q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << Solution(a, b, c) << '\n';
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
