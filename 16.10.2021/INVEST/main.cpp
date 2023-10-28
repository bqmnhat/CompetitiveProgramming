#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, Connected[100001], lc = 0;
vector<int> g[100001];
bool visited[100001];

void addEdge(int u, int v, bool directed)  {
    g[u].push_back(v);
    if (!directed)
        g[v].push_back(u);
}

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        addEdge(u,v,false);
    }
}

void DFS(int u) {
    Connected[lc]++;
    for (auto v: g[u]) {
        if (!visited[v]) {
            visited[v] = true;
            DFS(v);
        }
    }
}

int Solution() {
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            lc++;
            visited[i] = true;
            DFS(i);
        }
    }
    sort(Connected+1, Connected+1+lc, greater<int>());
    int ans = Connected[1] + Connected[2];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("INVEST.INP", "r", stdin);
    freopen("INVEST.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
