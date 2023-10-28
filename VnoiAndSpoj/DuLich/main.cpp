#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n, m, s, k, a[MaxN+5];
vector<int> g[MaxN+5], Pass[MaxN+5], path;
bool vis[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        Pass[u].push_back(1);
        Pass[v].push_back(1);
    }
    for (int i=1; i<=k; i++)
        cin >> a[i];
}

void DFS(int u) {
    vis[u] = true;
    for (int v: g[u])
        if (!vis[v])
            DFS(v);
}

void Solve() {
    DFS(s);
    for (int i=1; i<=k; i++) {
        if (!vis[a[i]]) {
            cout << "NIE";
            return;
        }
    }
    cout << "TAK\n";
    stack<int> stk;
    stk.push(s);
    while (!stk.empty()) {
        int u = stk.top();
        bool flag = true;
        for (int i=0; i<g[u].size(); i++) {
            int v = g[u][i];
            if (Pass[u][i] == 1) {
                Pass[u][i] = 0;
                stk.push(v);
                flag = false;
                break;
            }
        }
        if (flag) {
            path.push_back(u);
            stk.pop();
        }
    }
    cout << path.size() << ' ';
    for (int x: path)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> k;
    ReadData();
    Solve();
    return 0;
}
