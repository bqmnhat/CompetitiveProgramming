#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, q, tin[MaxN+1], tout[MaxN+1], counter;
ll a[MaxN+1], st[8*MaxN+1], d[MaxN+1], lazy[8*MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void Down(int v) {
    if (st[v] != 0) {
        st[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        st[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
    }
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    d[u] = d[p] + a[u];
    for (int v: g[u])
        if (v != p)
            DFS(v, u);
    tout[u] = counter;
}

void UpdateSt(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
        return;
    if ((l == tl) && (tr == r)) {
        st[v] += val;
        lazy[v] += val;
    }
    else {
        Down(v);
        int tm = ((tl + tr) >> 1);
        UpdateSt(v*2, tl, tm, l, min(r, tm), val);
        UpdateSt(v*2+1, tm+1, tr, max(l, tm+1), r, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll GetQuery(int v, int tl, int tr, int id) {
    if (tl == tr)
        return st[v];
    else {
        Down(v);
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            return GetQuery(v*2, tl, tm, id);
        else
            return GetQuery(v*2+1, tm+1, tr, id);
    }
}

void Solve() {
    DFS(1, -1);
    d[1] = a[1];
    counter = 0;
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int s;
            ll x;
            cin >> s >> x;
            UpdateSt(1, 1, 2*MaxN, tin[s], tout[s], x - a[s]);
            a[s] = x;
        }
        else {
            int s;
            cin >> s;
            ll ans = d[s] + GetQuery(1, 1, 2*MaxN, tin[s]);
            cout << ans << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
