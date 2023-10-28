#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, l, parent[MaxN+1][20], q, tin[MaxN+1], tout[MaxN+1], counter = 0, CurR = 1;
ll w[MaxN+1], SumW[MaxN+1], SumAll = 0;
vector<int> graph[MaxN+1];

void ReadGraph() {
    for (int i=1; i<=n; i++) {
        cin >> w[i];
        SumAll += w[i];
    }
    for (int i=2; i<=n; i++) {
        int u;
        cin >> u;
        graph[u].push_back(i);
    }
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    parent[u][0] = p;
    SumW[u] = w[u];
    for (int v: graph[u]) {
        if (v != p) {
            DFS(v, u);
            SumW[u] += SumW[v];
        }
    }
    counter++;
    tout[u] = counter;
}

void Preprocess() {
    l = log2(n);
    counter = 0;
    DFS(1, 1);
    for (int k=1; k<=l; k++)
        for (int i=1; i<=n; i++)
            parent[i][k] = parent[parent[i][k-1]][k-1];
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

int NearLCA(int u, int v) {
    for (int k = l; k>=0; k--)
        if (!IsAncestor(parent[u][k], v))
            u = parent[u][k];
    return u;
}

void Solve() {
    Preprocess();
    cin >> q;
    for (int i=1; i<=q; i++) {
        char cmd;
        cin >> cmd;
        if (cmd == 'S') {
            int u;
            cin >> u;
            if (u == CurR)
                cout << SumAll << '\n';
            else if (IsAncestor(u, CurR))
                cout << SumAll - SumW[NearLCA(CurR, u)]<< '\n';
            else
                cout << SumW[u] << '\n';
        }
        else {
            int u;
            cin >> u;
            CurR = u;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadGraph();
    Solve();
    return 0;
}
