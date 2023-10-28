#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int t, n, tin[MaxN+1], tout[MaxN+1], par[MaxN+1][20], h[MaxN+1], counter = 0;
ll dist[MaxN+1];
vector<pii> g[MaxN+1];

void ReadData() {
    int u, v;
    ll c;
    for (int i=1; i<=n; i++)
        g[i].clear();
    for (int i=1; i<n; i++) {
        cin >> u >> v >> c;
        g[u].push_back(pii(v, c));
        g[v].push_back(pii(u, c));
    }
}

void DFSPreprocess(int u, int p, int height) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    h[u] = height;
    for (pii tmpv: g[u]) {
        int v = tmpv.first;
        ll w = tmpv.second;
        if (v != p) {
            dist[v] = dist[u] + w;
            DFSPreprocess(v, u, height+1);
        }
    }
    tout[u] = counter;
}

bool IsAncestor(int Anc, int u) {
    return ((tin[Anc] <= tin[u]) && (tin[u] <= tout[Anc]));
}

void Preprocess() {
    counter = 0;
    memset(par, 0, sizeof(par));
    memset(dist, 0, sizeof(dist));
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    memset(h, 0, sizeof(h));
    DFSPreprocess(1, 1, 0);
    int l = log2(n);
    for (int j = 1; j<=l; j++)
        for (int i=1; i<=n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
}

int LCA(int a, int b) {
    if (IsAncestor(a, b))
        return a;
    if (IsAncestor(b, a))
        return b;
    int l = log2(n);
    for (int i=l; i>=0; i--)
        if (!IsAncestor(par[a][i], b))
            a = par[a][i];
    return par[a][0];
}

ll DistanceQuery(int a, int b) {
    int lca = LCA(a, b);
    ll ans = dist[a] + dist[b] - 2*dist[lca];
    return ans;
}

int KthNodeQuery(int a, int b, int k) {
    int lca = LCA(a, b), l = log2(n);
    int tmp = h[a] - h[lca] + 1;
    if (k <= tmp) {
        int dist = k - 1, cnt = 0;
        if (dist == 0)
            return a;
        for (int i=l; i>=0; i--) {
            if ((cnt + (1 << i)) < dist) {
                a = par[a][i];
                cnt += (1 << i);
            }
        }
        return par[a][0];
    }
    else {
        k -= tmp;
        int dist = h[b] - h[lca] - k, cnt = 0;
        if (dist == 0)
            return b;
        for (int i=l; i>=0; i--) {
            if ((cnt + (1 << i)) < dist) {
                b = par[b][i];
                cnt += (1 << i);
            }
        }
        return par[b][0];
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        Preprocess();
        string cmd;
        while ((cin >> cmd) && (cmd != "DONE")) {
            if (cmd == "DIST") {
                int a, b;
                cin >> a >> b;
                cout << DistanceQuery(a, b) << '\n';
            }
            else {
                int a, b, k;
                cin >> a >> b >> k;
                cout << KthNodeQuery(a, b, k) << '\n';
            }
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
