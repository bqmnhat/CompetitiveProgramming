#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, q;
ll a[MaxN+1], st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = a[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

ll MinQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 1e18;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return min(MinQuery(v*2, tl, tm, l, r), MinQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, n);
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k;
            ll u;
            cin >> k >> u;
            UpdateSt(1, 1, n, k, u);
        }
        else {
            int u ,v;
            cin >> u >> v;
            cout << MinQuery(1, 1, n, u, v) << '\n';
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
