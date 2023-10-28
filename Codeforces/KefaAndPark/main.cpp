#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[100001], ans = 0, ConCat[100001];
vector<int> graph[100001];
bool vis[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void DFS(int u, int p) {
    vis[u] = true;
    if (a[u])
        ConCat[u] = ConCat[p] + 1;
    else
        ConCat[u] = 0;
    if (ConCat[u] > m)
        return;
    int CntChild = 0;
    for (auto v: graph[u]) {
        if (v != p)
            CntChild++;
        if (!vis[v])
            DFS(v, u);
    }
    if ((CntChild == 0) && (ConCat[u] <= m))
        ans++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    DFS(1, 0);
    cout << ans;
    return 0;
}
