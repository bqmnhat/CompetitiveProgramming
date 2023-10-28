#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
struct StNode{
    ll Increment, Sum, SetAllTo;
    bool IsSet;
    void Reset() {
        Increment = 0;
        SetAllTo = 0;
        IsSet = false;
    }
};
int n, q;
ll a[MaxN+1], st[4*MaxN+1];
StNode lazy[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Down(int v, ll tl, ll tr) {
    ll tm = ((tl + tr) >> 1);
    if (lazy[v].IsSet) {
        lazy[v*2].IsSet = true;
        lazy[v*2].SetAllTo = lazy[v].SetAllTo;
        lazy[v*2].Increment = 0;
        lazy[v*2+1].IsSet = true;
        lazy[v*2+1].SetAllTo = lazy[v].SetAllTo;
        lazy[v*2+1].Increment = 0;
    }
    lazy[v*2].Increment += lazy[v].Increment;
    lazy[v*2+1].Increment += lazy[v].Increment;
    if (lazy[v].IsSet)
        st[v*2] = (tm - tl + 1LL)*lazy[v].SetAllTo;
    if (lazy[v].IsSet)
        st[v*2+1] = (tr - tm)*lazy[v].SetAllTo;
    st[v*2] += (tm - tl + 1LL)*lazy[v].Increment;
    st[v*2+1] += (tr - tm)*lazy[v].Increment;
    lazy[v].Reset();
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = a[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateSt(int v, int tl, int tr, int l, int r, int mode, ll val) {
    if (l > r)
        return;
    if ((l == tl) && (tr == r)) {
        if (mode == 0) {
            st[v] = (tr - tl + 1LL)*val;
            lazy[v].Increment = 0;
            lazy[v].SetAllTo = val;
            lazy[v].IsSet = true;
        }
        else {
            st[v] += (tr - tl + 1LL)*val;
            lazy[v].Increment += val;
        }
        return;
    }
    Down(v, tl, tr);
    int tm = ((tl + tr) >> 1);
    UpdateSt(v*2, tl, tm, l, min(r, tm), mode, val);
    UpdateSt(v*2+1, tm+1, tr, max(tm+1, l), r, mode, val);
    st[v] = st[v*2] + st[v*2+1];
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if ((l == tl) && (tr == r))
        return st[v];
    Down(v, tl, tr);
    int tm = ((tl + tr) >> 1);
    return (GetSum(v*2, tl, tm, l, min(r, tm)) + GetSum(v*2+1, tm+1, tr, max(tm+1, l), r));
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            ll x;
            cin >> a >> b >> x;
            UpdateSt(1, 1, n, a, b, 1, x);
        }
        else if (cmd == 2) {
            int a, b;
            ll x;
            cin >> a >> b >> x;
            UpdateSt(1, 1, n, a, b, 0, x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << GetSum(1, 1, n, a, b) << '\n';
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
    BuildSt(1, 1, n);
    Solve();
    return 0;
}
