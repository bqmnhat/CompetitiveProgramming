#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int n, dist[MaxN+5];
vector<int> g[MaxN+5];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFS(int u, int p) {
    for (int v: g[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            DFS(v, u);
        }
    }
}

int Solution() {
    dist[1] = 0;
    DFS(1, -1);
    int pos = 1;
    for (int i=1; i<=n; i++)
        if (dist[i] > dist[pos])
            pos = i;
    memset(dist, 0, sizeof(dist));
    DFS(pos, -1);
    int ans = 0;
    for (int i=1; i<=n; i++)
        ans = max(ans, dist[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
