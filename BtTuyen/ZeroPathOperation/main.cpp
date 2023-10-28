#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, m, deg[100001], w[100001], ans = 0;
bool visited[100001];
queue <int> q;
class Graph {
    list<int> * adjlist;
    int n;
public:
    Graph(int v) {
        adjlist = new list<int> [v+1];
        n = v;
    }
    void addedge(int u, int v, bool bi) {
        adjlist[u].push_back(v);
        if (bi)
            adjlist[v].push_back(u);
    }
    void BFS(int x);
};

void Init() {
    for (int i=1; i<=m; i++)
        deg[i] = 0;
    for (int i=1; i<=m; i++)
        visited[i] = false;
}

void Graph::BFS(int x) {
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if ((w[u] != 0) && (deg[u] >= 2))
            ans++;
        for (auto i = adjlist[u].begin(); i!= adjlist[u].end(); i++) {
            if (!visited[*i]) {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}

void Solve() {
    Graph g(m);
    int u,v;
    ans = 0;
    Init();
    for (int i=1; i<m; i++) {
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        g.addedge(u,v,true);
    }
    for (int i=1; i<=m; i++)
        cin >> w[i];
    for (int i=1; i<=m; i++){
        if (!visited[i])
            g.BFS(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> m;
        Solve();
        cout << ans << '\n';
    }
    return 0;
}
