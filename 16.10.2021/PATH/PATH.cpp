#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100001], la = 0;
vector<int> g[100001];
bool visited[100001];

void addEdge(int u, int v, bool directed) {
    g[u].push_back(v);
    if (!directed)
        g[v].push_back(u);
}

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        addEdge(u,v,true);
    }
}

void PrintAns() {
    for (int i=1; i<=la; i++)
        cout << ans[i] << ' ';
}

bool DFS(int u) {
    la++;
    ans[la] = u;
    if (u == n)
        return true;
    for (auto v: g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (DFS(v))
                return true;
        }
    }
    la--;
    return false;
}

void Solve() {
    visited[1] = true;
    if (DFS(1))
        PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PATH.INP", "r", stdin);
    freopen("PATH.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
