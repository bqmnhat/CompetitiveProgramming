#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,t,q,l,tIn[1001], tOut[1001], up[1001][20], timer = 0;
bool IsNotRoot[1001];
vector<int> g[1001];

int LogOf(int x) {
    int tmp = 0;
    while (x > 0) {
        tmp++;
        x = (x >> 1);
    }
    return tmp;
}

void MakeGraph() {
    int m, v;
    for (int i=1; i<=n; i++)
        g[i].clear();
    for (int i=1; i<=n; i++) {
        cin >> m;
        for (int j=1; j<=m; j++) {
            cin >> v;
            IsNotRoot[v] = true;
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
}

void DFS(int u, int p) {
    timer++;
    tIn[u] = timer;
    up[u][0] = p;
    for (int i=1; i<=l; ++i)
        up[u][i] = up[up[u][i-1]][i-1];
    for (int v: g[u]) {
        if (v != p)
            DFS(v, u);
    }
    timer++;
    tOut[u] = timer;
}

bool CheckAnCestor(int u, int v) {
    return ((tIn[u] <= tIn[v]) && (tOut[u] >= tOut[v]));
}

void Init() {
    l = LogOf(n);
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=l; j++)
            up[i][j] = n;
    }
    int root = 1;
    for (int i=1; i<=n; i++) {
        if (!IsNotRoot[i]) {
            root = i;
            break;
        }
    }
    DFS(root, root);
}

int LCA(int u, int v) {
    if (CheckAnCestor(u, v))
        return u;
    if (CheckAnCestor(v,u))
        return v;
    for (int i=l; i>=0; --i) {
        if (!CheckAnCestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        MakeGraph();
        Init();
        cin >> q;
        cout << "Case " << i << ": \n";
        for (int i=1; i<=q; i++) {
            int u, v;
            cin >> u >> v;
            cout << LCA(u,v) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
