// Topo sort with priority_queue
#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, m, indeg[MaxN+1];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
}

vector<int> TopoSort() {
    vector<int> res;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        res.push_back(u);
        for (int v: g[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                pq.push(v);
        }
    }
    return res;
}

void Solve() {
    for (int i=1; i<=n; i++)
        if (!indeg[i])
            pq.push(i);
    vector<int> ans = TopoSort();
    for (int i=1; i<=n; i++) {
        if (indeg[i] > 0) {
            cout << "-1";
            return;
        }
    }
    for (int x: ans)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
