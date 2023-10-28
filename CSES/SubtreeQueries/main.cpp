#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
ll St[8*MaxN+1], a[MaxN+1];
int tin[MaxN+1], tout[MaxN+1], counter = 0, n, q;
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

void DFSET(int u, int p) { // Euler Tour
    counter++;
    tin[u] = counter;
    for (int v: g[u])
        if (v != p)
            DFSET(v, u);
    counter++;
    tout[u] = counter;
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        St[v] = val;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        St[v] = St[v*2] + St[v*2+1];
    }
}

ll SumQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0LL;
    if ((l <= tl) && (tr <= r))
        return St[v];
    int tm = (tl + tr)/2;
    return (SumQuery(v*2, tl, tm, l, r) + SumQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    for (int i=1; i<=n; i++)
        UpdateSt(1, 1, 2*MaxN, tin[i], a[i]);
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int s;
            ll x;
            cin >> s >> x;
            UpdateSt(1, 1, 2*MaxN, tin[s], x);
        }
        else {
            int s;
            cin >> s;
            cout << SumQuery(1, 1, 2*MaxN, tin[s], tout[s]) << '\n';
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
    DFSET(1, -1);
    Solve();
    return 0;
}
