#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
typedef long long ll;
int c, n, q, tin[MaxN+1], tout[MaxN+1], counter = 0;
vector<int> g[MaxN+1];
ll stP[4*MaxN+1], stV[4*MaxN+1], SumP, SumV;

void ReadData() {
    int u, v;
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void DFSPreprocess(int u, int p) {
    counter++;
    tin[u] = counter;
    for (int v: g[u])
        if (v != p)
            DFSPreprocess(v, u);
    tout[u] = counter;
}

int WhichIsNotAncestor(int u, int v) {
    if ((tin[u] <= tin[v]) && (tin[v] <= tout[u]))
        return v;
    return u;
}

void UpdateSt(ll st[4*MaxN+1], int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] += val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(st, v*2, tl, tm, id, val);
        else
            UpdateSt(st, v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll GetVal(ll st[4*MaxN+1], int v, int tl, int tr, int l, int r) {
    if ((l > tr) || (r < tl))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return GetVal(st, v*2, tl, tm, l, r) + GetVal(st, v*2+1, tm+1, tr, l, r);
}

void SolveTestCase() {
    SumP = SumV = 0;
    ll x;
    int a, b;
    memset(stV, 0, sizeof(stV));
    memset(stP, 0, sizeof(stP));
    memset(tin, 0, sizeof(tin));
    memset(tout, 0, sizeof(tout));
    for (int i=1; i<=n; i++)
        g[i].clear();
    ReadData();
    counter = 0;
    DFSPreprocess(1, -1);
    for (int i=1; i<=q; i++) {
        cin >> a >> b >> x;
        if (x != 0) {
            UpdateSt(stV, 1, 1, n, tin[a], x);
            UpdateSt(stP, 1, 1, n, tin[b], x);
            SumV += x;
            SumP += x;
        }
        else {
            int Child = WhichIsNotAncestor(a, b);
            ll Vv = GetVal(stV, 1, 1, n, tin[Child], tout[Child]);
            ll Vp = GetVal(stP, 1, 1, n, tin[Child], tout[Child]);
            ll TmpV = SumV - Vv;
            ll TmpP = SumP - Vp;
            ll ans = max(TmpV, TmpP) - min(TmpV, TmpP);
            cout << ans << '\n';
        }
    }
}

void Solve() {
    for (int i=1; i<=c; i++) {
        cin >> n >> q;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c;
    Solve();
    return 0;
}
