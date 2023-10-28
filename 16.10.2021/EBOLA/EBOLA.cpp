#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, m, ans[100001], la = 0;
vector<int> g[100001];
bool visited[100001];

void addEdge(int u, int v, bool directed) {
    g[u].push_back(v);
    if (!directed)
        g[v].push_back(u);
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        int m;
        cin >> m;
        for (int j=1; j<=m; j++) {
            int v;
            cin >> v;
            addEdge(i,v,false);
        }
    }
}

void PrintAns() {
    cout << la << '\n';
    sort(ans+1, ans+1+la);
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
    visited[k] = true;
    DFS(k);
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("EBOLA.INP", "r", stdin);
    freopen("EBOLA.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
