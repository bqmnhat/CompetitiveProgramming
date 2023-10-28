#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
vector<pil> g[200001];
int n;
ll len[200001], a[200001];
bool vis[200001];

void ReadGraph() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int u, v, w;
    for (int i=1; i<n; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pil(v, w));
        g[v].push_back(pil(u, w));
    }
}

ll DFS(int u) {
    vis[u] = true;
    ll MaxAns = 0;
    int C = 0;
    for (auto tmpv: g[u]) {
        int v = tmpv.first;
        ll w = tmpv.second;
        if (!vis[v]) {
            C++;
            MaxAns = max(MaxAns, DFS(v) + w);
        }
    }
    if (C == 0)
        return a[u];
    return MaxAns;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        cout << DFS(i) << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RGB.INP", "r", stdin);
    freopen("RGB.OUT", "w", stdout);
    cin >> n;
    ReadGraph();
    Solve();
    return 0;
}
