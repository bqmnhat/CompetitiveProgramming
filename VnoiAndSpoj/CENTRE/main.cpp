#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30000
using namespace std;
typedef pair<int, int> pii;
int n, m, cnt[MaxN+1], cntRev[MaxN+1], d[MaxN+1], drev[MaxN+1];
vector<pii> g[MaxN+1];
const int SuperMax = 1e9;

void ReadGraph() {
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
}

void Dijkstra(int src, int cnt[MaxN+1], int d[MaxN+1]) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, src));
    cnt[src] = 1;
    d[src] = 0;
    while (!pq.empty()) {
        pii tmpu = pq.top();
        pq.pop();
        int u = tmpu.second;
        if (tmpu.first > d[u])
            continue;
        for (auto tmpv: g[u]) {
            int v = tmpv.first, w = tmpv.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push(pii(d[v], v));
                cnt[v] = cnt[u];
            }
            else if (d[u] + w == d[v])
                cnt[v] += cnt[u];
        }
    }
}

void Solve() {
    for (int i=1; i<=n; i++)
        d[i] = drev[i] = 1e9;
    Dijkstra(1, cnt, d);
    Dijkstra(n, cntRev, drev);
    vector<int> DelVert;
    DelVert.clear();
    for (int i=2; i<n; i++)
        if (!((d[i] + drev[i] == d[n]) && (cnt[i]*cntRev[i] == cnt[n])))
            DelVert.push_back(i);
    cout << DelVert.size() << '\n';
    for (int x: DelVert)
        cout << x << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadGraph();
    Solve();
    return 0;
}
