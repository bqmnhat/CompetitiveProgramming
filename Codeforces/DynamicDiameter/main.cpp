#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef pair<int, int> pii;
int n, DpU[MaxN+1], DpD[MaxN+1];
vector<int> g[MaxN+1];
vector<pii> dist[MaxN+1];

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void CalDpD(int u, int p) {
    DpD[u] = 1;
    for (int v: g[u]) {
        if (v == p)
            continue;
        CalDpD(v, u);
        dist[u].push_back(pii(DpD[v], v));
    }
    if (dist[u].size() > 0) {
        sort(dist[u].begin(), dist[u].end(), greater<pii>());
        DpD[u] += dist[u][0].first;
    }
}

void CalDpU(int u, int p) {
    DpU[u] = 0;
    if (p != -1) {
        DpU[u] = DpU[p] + 1;
        if (dist[p].size() > 0) {
            if (dist[p][0].second != u)
                DpU[u] = max(DpU[u], dist[p][0].first + 1);
            else if (dist[p].size() > 1)
                DpU[u] = max(DpU[u], dist[p][1].first + 1);
        }
    }
    for (int v: g[u])
        if (v != p)
            CalDpU(v, u);
}

void Solve() {
    int d = 0;
    CalDpD(1, -1);
    CalDpU(1, -1);
    for (int i=1; i<=n; i++) {
        d = max(d, DpD[i] + DpU[i]);
        if (dist[i].size() > 1)
            d = max(d, dist[i][0].first + dist[i][1].first);
    }
    for (int i=1; i<=n; i++) {
        int tmpD = d;
        tmpD = max(tmpD, DpD[i]+1);
        tmpD = max(tmpD, DpU[i]+2);
        cout << tmpD-1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
