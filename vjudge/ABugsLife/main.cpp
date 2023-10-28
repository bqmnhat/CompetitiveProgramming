#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
int t, n, m, trace[MaxN+1], status[MaxN+1];
vector<int> g[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=n; i++)
        g[i].clear();
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool DFS(int u) {
    status[u] = 1;
    for (int v: g[u]) {
        if (status[v] == 0) {
            trace[v] = u;
            if (DFS(v) == false)
                return false;
        }
        else if (status[v] == 1) {
            int tmpu = u, cnt = 1;
            while (tmpu != v) {
                cnt++;
                tmpu = trace[tmpu];
            }
            if (cnt&1)
                return false;
        }
    }
    status[u] = 2;
    return true;
}

bool Solution() {
    for (int i=0; i<=n; i++) {
        trace[i] = -1;
        status[i] = 0;
    }
    for (int i=1; i<=n; i++)
        if ((status[i] == 0) && (DFS(i) == false))
            return false;
    return true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        ReadGraph();
        cout << "Scenario #" << i << ": " << '\n';
        if (Solution())
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
