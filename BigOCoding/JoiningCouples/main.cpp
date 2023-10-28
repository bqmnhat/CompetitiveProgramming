#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
typedef long long ll;
int n, q, InWhichSCC[MaxN+1], f[MaxN+1], counter, num[MaxN+1], low[MaxN+1], cnt_scc, InCycle[MaxN+1], CycleSize[MaxN+1], CycleDist[MaxN+1], parent[MaxN+1][20], tin[MaxN+1], tout[MaxN+1], h[MaxN+1];
bool found[MaxN+1];
vector<int> g[MaxN+1], DAG[MaxN+1], NewG[MaxN+1];
stack<int> stk;

//DSU Struct for calculating Cycle size, Distance from node a to node b in a cycle

struct DSU {
    int par[MaxN+1];

    void Init(int n = 0) {
        par[0] = -1;
        for (int i=1; i<=n; i++)
            par[i] = i;
        for (int i=n+1; i<=MaxN; i++)
            par[i] = -1;
    }

    void MakeSet(int u) {
        if (par[u] == -1)
            par[u] = u;
    }

    int FindSet(int u) {
        if (par[u] == -1)
            return -1;
        if (par[u] == u)
            return u;
        return (par[u] = FindSet(par[u]));
    }

    bool UnionSet(int u, int v) {
        u = FindSet(u);
        v = FindSet(v);
        if (u != v) {
            par[v] = u;
            return true;
        }
        return false;
    }
};

DSU dsu;

//Initialization

void ReadGraph() {
    for (int i=1; i<=n+1; i++) {
        g[i].clear();
        NewG[i].clear();
    }
    for (int i=1; i<=n; i++) {
        cin >> f[i];
        g[i].push_back(f[i]);
    }
}

void Init() {
    counter = 0;
    cnt_scc = 0;
    for (int i=1; i<=n+1; i++) {
        num[i] = low[i] = CycleDist[i] = CycleSize[i] = tin[i] = tout[i] = h[i] = 0;
        InWhichSCC[i] = InCycle[i] = -1;
        found[i] = false;
    }
}

//Tarjan and make DAG (SCC compression)

void DFSTarjan(int u) {
    counter++;
    low[u] = num[u] = counter;
    stk.push(u);
    for (int v: g[u]) {
        if (!found[v]) {
            if (num[v])
                low[u] = min(low[u], num[v]);
            else {
                DFSTarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (num[u] == low[u]) {
        cnt_scc++;
        int v;
        do {
            v = stk.top();
            stk.pop();
            InWhichSCC[v] = cnt_scc;
            found[v] = true;
        } while (v != u);
    }
}

void Tarjan() {
    for (int i=1; i<=n; i++)
        if (!num[i])
            DFSTarjan(i);
    for (int i=1; i<=n; i++)
        if (InWhichSCC[i] == -1)
            InWhichSCC[i] = i;
}

void MakeDAG() {
    for (int i=1; i<=n; i++)
        DAG[i].clear();
    for (int u=1; u<=n; u++)
        for (int v: g[u])
            if (InWhichSCC[u] != InWhichSCC[v])
                DAG[InWhichSCC[u]].push_back(InWhichSCC[v]);
}

// Virtual point Establishment

void VirtualPointInit() {
    int VirPnt = n+1;
    for (int i=1; i<=n; i++) {
        if (DAG[InWhichSCC[i]].size() == 0) {// This is a node of a cycle
            NewG[VirPnt].push_back(i);
            NewG[i].push_back(VirPnt);
        }
        else {
            NewG[i].push_back(f[i]);
            NewG[f[i]].push_back(i);
        }
    }
}

// Finding the nearest node a to u in the cycle, we need to use a trick of DSU which we define the parent of every set is a node of a cycle, then for each node u which is not in any cycle will be connected to their f[u]
// Now we will initialize that DSU data

void DSUInitialization() {
    dsu.Init(n);
    for (int i=1; i<=n; i++)
        if (DAG[InWhichSCC[i]].size() != 0)
            dsu.UnionSet(f[i], i);
}

// Calculating Cycles' size and distance in cycle

void CycleCalculation() {
    int Cnt_Cycle = 0;
    for (int i=1; i<=n; i++) {
        if ((DAG[InWhichSCC[i]].size() == 0) && (InCycle[i] == -1)) {
            Cnt_Cycle++;
            int cnt_dist = 0;
            for (int u = i; InCycle[u] == -1; u = f[u], CycleSize[Cnt_Cycle]++, cnt_dist++) {
                InCycle[u] = Cnt_Cycle;
                CycleDist[u] = cnt_dist;
            }
        }
    }
}

// LCA for NewG to calculate distance between two nodes and determine whether there exist a cycle on the path between those two nodes

void DFSLCAInit(int u, int p, int height) {
    counter++;
    tin[u] = counter;
    h[u] = height;
    parent[u][0] = p;
    for (int v: NewG[u])
        if (v != p)
            DFSLCAInit(v, u, height + 1);
    counter++;
    tout[u] = counter;
}

void LCAInitializtion() {
    counter = 0;
    DFSLCAInit(n+1, n+1, 0);
    int l = log2(n+1);
    for (int j=1; j<=l; j++)
        for (int i=1; i<=n+1; i++)
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
    int l = log2(n+1);
    for (int i=l; i>=0; i--)
        if (!IsAncestor(parent[u][i], v))
            u = parent[u][i];
    return parent[u][0];
}

// Answering Queries Process

void AnsweringQuerries() {
    cin >> q;
    int u, v;
    for (int i=1; i<=q; i++) {
        cin >> u >> v;
        int lca = LCA(u, v);
        if (lca == n+1) { // lca is virtual node => Cycle exist on path from u to v
            int U = dsu.FindSet(u), V = dsu.FindSet(v); // U is node in cycle nearest to u, V is node in cycle nearest to V
            if (InCycle[U] == InCycle[V]) {
                int d_ToCycle = abs(h[u] - h[U]) + abs(h[v] - h[V]);
                int d_InCycle = min(abs(CycleDist[U] - CycleDist[V]), CycleSize[InCycle[U]] - abs(CycleDist[U] - CycleDist[V]));
                int ans = d_ToCycle + d_InCycle;
                cout << ans << '\n';
            }
            else
                cout << "-1\n";
        }
        else {
            int ans = abs(h[u] - h[lca]) + abs(h[v] - h[lca]);
            cout << ans << '\n';
        }
    }
}

// Solvving TestCases

void SolveTestCase() {
    ReadGraph();
    Init();
    Tarjan();
    MakeDAG();
    VirtualPointInit();
    DSUInitialization();
    CycleCalculation();
    LCAInitializtion();
    AnsweringQuerries();
}

void Solve() {
    while (cin >> n)
        SolveTestCase();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
