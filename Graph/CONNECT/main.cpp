#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
bool a[102][102], Free[101];

void ReadData() {
    int u,v;
    for (int i = 1; i<=m; i++) {
        cin >> u >> v;
        a[u][v] = true;
        a[v][u] = true;
    }
    for (int i=1; i<=n; i++) {
        a[i][i] = true;
    }
}

void Warshall() {
    for (int k=1; k<=n; k++) {
        for (int u=1; u<=n; u++) {
            for (int v=1; v<=n; v++) {
                a[u][v] = a[u][v] or (a[u][k] and a[k][v]);
                a[v][u] = a[u][v];
            }
        }
    }
}

void Solve() {
    int u = 1;
    while (u != 0) {
        cout << "Connection: " << '\n';
        int v = 0;
        for (int i=1; i<=n; i++) {
            if (a[u][i]) {
                cout << i << " ";
                Free[i] = true;
            }
            else if ((v == 0) && (Free[i] == false))
                v = i;
        }
        cout << '\n';
        u = v;
    }
}

int main()
{
    freopen("CONNECT.INP", "r", stdin);
    freopen("CONNECT.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Warshall();
    Solve();
    return 0;
}
