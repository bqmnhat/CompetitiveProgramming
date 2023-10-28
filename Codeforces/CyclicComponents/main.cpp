#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, deg[200001];
vector<int> graph[200001], stk;
bool vis[200001];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void DFS(int u, int p) {
    stk.push_back(u);
    if (p != -1)
        deg[u]++;
    vis[u] = true;
    for (auto v: graph[u]) {
        if (v == p) continue;
        deg[u]++;
        if (!vis[v])
            DFS(v, u);
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            stk.clear();
            DFS(i, -1);
            bool IsCCCycle = true;
            while (stk.size() != 0) {
                int u = stk.back();
                stk.pop_back();
                if (deg[u] != 2)
                    IsCCCycle = false;
            }
            if (IsCCCycle)
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    cout << Solution();
    return 0;
}
