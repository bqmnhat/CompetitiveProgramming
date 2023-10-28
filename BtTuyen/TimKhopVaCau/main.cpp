#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool visited[10001], isCutVertex[10001], Ans[10001];
int n, m, t, discTime[10001], low[10001], bridges = 0, CutVertices = 0;
vector<int> g[10001];

void addEdge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

void DFSFindCutVertex(int u, int& time, int parent) {
    int children = 0;
    visited[u] = true;
    time++;
    discTime[u] = low[u] = time;
    for (auto v: g[u]) {
        if (!visited[v]) {
            children++;
            DFSFindCutVertex(v, time, u);
            low[u] = min(low[u], low[v]);
            if ((parent != -1) && (low[v] >= discTime[u]) && (!Ans[u])) {
                CutVertices++;
                Ans[u] = true;
            }
        }
        else if (v != parent)
            low[u] = min(low[u], discTime[v]);
    }
    if ((parent == -1) && (children > 1)) {
        Ans[u] = true;
        CutVertices++;
    }
}

void DFSFindBridges(int u, int& time, int parent) {
    visited[u] = true;
    time++;
    discTime[u] = low[u] = time;
    for (auto v: g[u]) {
        if (!visited[v]) {
            DFSFindBridges(v, time, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > discTime[u])
                bridges++;
        }
        else if (v != parent)
            low[u] = min(low[u], discTime[v]);
    }
}

void Solve()
{
    int time = 0;
    for (int u = 1; u <= n; u++)
        if (!visited[u])
            DFSFindCutVertex(u, time, -1);
    for (int i=1; i<=10001; i++) {
        visited[i] = false;
        discTime[i] = 0;
        low[i] = 0;
    }
    time = 0;
    for (int u = 1; u <= n; u++)
        if (!visited[u])
            DFSFindBridges(u, time, -1);
    cout << CutVertices << ' ' << bridges;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
    }
    Solve();
    return 0;
}
