#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n, m, vis[MaxN+1], ans[MaxN+1];
pii Edges[MaxN+1];
vector<int> g[MaxN+1];
stack<int> stk;
map<pii, int> ma;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        Edges[i] = pii(u, v);
        ma[Edges[i]] = i;
        g[u].push_back(v);
    }
}

void DFS(int u) {
    for (int v: g[u]) {
        if (vis[v] == 0) {
            vis[v] = 1;
            DFS(v);
        }
        else if (vis[v] == 1)
            ans[ma[pii(u, v)]] = 2;
    }
    vis[u] = 2;
}

void FindAllCycle() {
    for (int i=1; i<=n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            DFS(i);
        }
    }
}

void Solve() {
    if (m == 0) {
        cout << "0";
        return;
    }
    bool HaveCycle = false;
    for (int i=1; i<=m; i++) {
        if (ans[i] == 2)
            HaveCycle = true;
        else
            ans[i] = 1;
    }
    if (HaveCycle)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
    for (int i=1; i<=m; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    FindAllCycle();
    Solve();
    return 0;
}
