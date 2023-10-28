#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n,m,t,cntEdge, cntVer;
vector<int> g[MaxN+1];
bool visited[MaxN+1], IsCycle;

void InitVis() {
    for (int i=1; i<=n; i++)
        visited[i] = false;
}

void InitGraph() {
    for (int i=1; i<=n; i++)
        g[i].clear();
}

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u) {
    if (g[u].size() != 2)
        IsCycle = false;
    visited[u] = true;
    cntEdge += g[u].size();
    cntVer++;
    for (auto v : g[u])
        if (!visited[v])
            DFS(v);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        InitVis();
        InitGraph();
        ReadData();
        int ans1 = 0, ans2 = 0;
        for (int i=1; i<=n; i++) {
            int cnt = 0;
            if (!visited[i]) {
                cntEdge = cntVer = 0;
                IsCycle = true;
                DFS(i);
                cntEdge = cntEdge/2;
                if (cntVer - 1 == cntEdge)
                    ans1++;
                if (IsCycle)
                    ans2++;
            }
        }
        cout << ans1 << ' ' << ans2 << '\n';
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
