#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
int n, m, indeg[MaxN+1];
bool vis[MaxN+1];
set<int> pq;
vector<int> g[MaxN+1], ans;

void ReadData() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    for (int i=1; i<=n; i++)
        if (indeg[i] == 0)
            pq.insert(i);
}

void Solve() {
    while (!pq.empty()) {
        int u = (*pq.begin());
        pq.erase(pq.find(u));
        ans.push_back(u);
        vis[u] = true;
        for (int v: g[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                pq.insert(v);
        }
    }
    for (int i=1; i<=n; i++) {
        if (indeg[i] > 0) {
            cout << "-1";
            return;
        }
    }
    for (int i=1; i<=n; i++)
        if (!vis[i])
            ans.push_back(i);
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
