#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
using namespace std;
typedef long long ll;
const ll INF = 1e16 + 7;
int n, m, q;
ll dist[MaxN+5][MaxN+5];

void Init() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

void ReadData() {
    int u, v;
    ll w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[u][v], w);
    }
}

void FindDist() { //Floyd-Warshall
    for (int med=1; med<=n; med++)
        for (int u=1; u<=n; u++)
            for (int v=1; v<=n; v++)
                if (dist[u][v] > dist[u][med] + dist[med][v])
                    dist[u][v] = dist[u][med] + dist[med][v];
}

void Solve() {
    Init();
    ReadData();
    FindDist();
    for (int i=1; i<=q; i++) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] >= INF)
            cout << "-1\n";
        else
            cout << dist[u][v] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    Solve();
    return 0;
}
