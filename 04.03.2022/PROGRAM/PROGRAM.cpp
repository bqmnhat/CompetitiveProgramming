#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll t[100001], st[100001];
vector<int> graph[100001];
bool vis[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> t[i];
    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
    }
}

void TopoSort(int u) {
    vis[u] = true;
    ll StMax = 1;
    for (auto v: graph[u]) {
        if (!vis[v])
            TopoSort(v);
        StMax = max(StMax, (st[v] + t[v]));
    }
    st[u] = StMax;
}

void Solve() {
    for (int i=1; i<=n; i++)
        if (!vis[i])
            TopoSort(i);
    ll Sum = 0;
    for (int i=1; i<=n; i++)
        Sum = max(Sum, st[i] + t[i]-1LL);
    cout << Sum << '\n';
    for (int i=1; i<=n; i++)
        cout << st[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PROGRAM.INP", "r", stdin);
    freopen("PROGRAM.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
