#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, q;
ll x[MaxN+1], st[4*MaxN+1], lazy[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = x[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void down(int v) {
    st[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    st[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void UpdateSt(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
        return;
    if ((l == tl) && (tr == r)) {
        lazy[v] += val;
        st[v] += val;
        return;
    }
    down(v);
    int tm = ((tl + tr) >> 1);
    UpdateSt(v*2, tl, tm, l, min(tm, r), val);
    UpdateSt(v*2+1, tm+1, tr, max(l, tm+1), r, val);
    st[v] = st[v*2] + st[v*2+1];
}

ll GetVal(int v, int tl, int tr, int id) {
    if (tl == tr)
        return st[v];
    else {
        down(v);
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            return GetVal(v*2, tl, tm, id);
        else
            return GetVal(v*2+1, tm+1, tr, id);
    }
}

void Solve() {
    BuildSt(1, 1, n);
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            UpdateSt(1, 1, n, a, b, u);
        }
        else {
            int k;
            cin >> k;
            cout << GetVal(1, 1, n, k) << '\n';
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
