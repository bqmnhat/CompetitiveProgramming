#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n = 0, m, Edge[1001][1001];
vector<int> path;

void ReadGraph() {
    for (int i=1; i<=T; i++) {
        int u, v;
        cin >> m >> u;
        n = max(n, u);
        for (int j=1; j<=m; j++) {
            cin >> v;
            Edge[u][v]++;
            n = max(n, v);
            u = v;
        }
    }
}

void FindEulerPath(int u) {
    for (int v = 1; v<=n; v++) {
        if (Edge[u][v] > 0) {
            Edge[u][v]--;
            FindEulerPath(v);
        }
    }
    path.push_back(u);
}

void Solve() {
    FindEulerPath(1);
    cout << path.size() - 1 << ' ';
    reverse(path.begin(), path.end());
    for (auto v : path)
        cout << v << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    ReadGraph();
    Solve();
    return 0;
}
