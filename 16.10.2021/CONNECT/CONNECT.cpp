#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100001], la;
vector<int> g[100001];
bool visited[100001];

void addEdge(int u, int v, bool directed) {
    g[u].push_back(v);
    if (!directed)
        g[v].push_back(u);
}

void ReadData() {
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        addEdge(u,v,false);
    }
}

void PrintAns() {
    for (int i=1; i<=la; i++)
        cout << ans[i] << ' ';
}

void DFS(int u) {
    la++;
    ans[la] = u;
    for (auto v: g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            DFS(v);
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            la = 0;
            visited[i] = true;
            DFS(i);
            PrintAns();
            cout << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CONNECT.INP", "r", stdin);
    freopen("CONNECT.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
