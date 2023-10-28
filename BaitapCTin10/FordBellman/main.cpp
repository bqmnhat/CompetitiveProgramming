#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, e, dist[1001], trace[1001], g[1001][1001], s;

void ReadGraph() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            g[i][j] = 1e9;
    for (int i=1; i<=e; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
}

void PrintAns() {
    for (int i=1; i<=n; i++)
        cout << i << " " << dist[i] << '\n';
}

void FordBellman(int s) {
    for (int i=1; i<=n; i++) {
        dist[i] = g[s][i];
        trace[i] = s;
    }
    dist[s] = 0;
    for (int v=1; v<=n; v++) {
        if (v == s)
            continue;
        for (int u = 1; u<=n; u++) {
            if (dist[v] > dist[u] + g[u][v]) {
                dist[v] = dist[u] + g[u][v];
                trace[v] = u;
            }
        }
    }
}

int main()
{
    cin >> n >> e >> s;
    ReadGraph();
    FordBellman(s);
    PrintAns();
    return 0;
}
