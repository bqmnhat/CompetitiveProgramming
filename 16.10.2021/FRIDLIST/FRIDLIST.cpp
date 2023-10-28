#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,deg[51],f[51], Day = 0;
int g[51][51];

void addEdge(int u, int v) {
    g[u][v] = g[v][u] = Day;
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        addEdge(u,v);
    }
}

void Init() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            g[i][j] = -1;
}

void Solve() {
    int FriendToday = 1;
    while (FriendToday != 0) {
        FriendToday = 0;
        Day++;
        for (int i=1; i<=n; i++) {
            for (int u = 1; u <= n; u++) {
                if ((g[i][u] != -1) && (g[i][u] != Day)) {
                    for (int v = 1; v <= n; v++) {
                        if ((g[u][v] != -1) && (g[u][v] != Day) && (g[i][v] == -1) && (v != i)) {
                            addEdge(i,v);
                            FriendToday++;
                        }
                    }
                }
            }
        }
        if (FriendToday != 0)
            f[Day] = FriendToday;
        else
            Day--;
    }
    cout << Day << '\n';
    for (int i = 1; i<=Day; i++)
        cout << f[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FRIDLIST.INP", "r", stdin);
    freopen("FRIDLIST.OUT", "w", stdout);
    cin >> n >> m;
    Init();
    ReadData();
    Solve();
    return 0;
}
