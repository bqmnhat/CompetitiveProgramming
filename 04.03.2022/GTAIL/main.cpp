#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0, TailLen[100001], st;
vector<int> graph[100001];
bool vis[100001];

void ReadGraph() {
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int DFS(int u) {
    vis[u] = true;
    int Tail = 1;
    for (auto v: graph[u]) {
        if ((!vis[v]) && (graph[v].size() <= 2))
            Tail += DFS(v);
    }
    return Tail;
}

int Solution() {
    for (int i=1; i<=n; i++)
        if ((graph[i].size() == 1) && (!vis[i]))
            ans = max(ans,DFS(i));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GTAIL.INP", "r", stdin);
    freopen("GTAIL.OUT", "w", stdout);
    cin >> n >> m;
    ReadGraph();
    cout << Solution();
    return 0;
}
