#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, depth[100001];
vector<int> g[100001];

void addEdge(int u, int v, bool directed) {
    g[u].push_back(v);
    if (!directed) {
        g[v].push_back(u);
    }
}

void ReadData() {
    for (int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        addEdge(u,v,false);
    }
}

void DFS(int u, int p) {
    for (auto v: g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1LL;
        DFS(v, u);
    }
}

long long Solution() {
    depth[1] = 1;
    DFS(1, 0);
    long long ans = 0;
    for (int i=1; i<=n; i++)
        ans += depth[i];
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
