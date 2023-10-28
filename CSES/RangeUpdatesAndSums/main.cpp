#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, q;
ll a[MaxN+1], st[4*MaxN+1];
pii lazy[MaxN+1]; // lazy[i].second == 0 means segment i is reset and new value is assigned, lazy.second == 1 means segment is still increasing

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Down(int v) {
    lazy[v*2].first = lazy[v*2].first*lazy[v].second + lazy[v].first;
    lazy[v*2].second = lazy[v].second;
    st[v*2] = st[v*2]*lazy[v].second + lazy[v].first;
    lazy[v*2+1].first = lazy[v*2+1].first*lazy[v].second + lazy[v].first;
    lazy[v*2+1].second = lazy[v].second;
    st[v*2+1] = st[v*2+1]*lazy[v].second + lazy[v].first;
    lazy[v] = pii(0, 0);
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
        st[v] = st[v]*1LL*mode + val;
        lazy[v].first = lazy[v].first * 1LL * mode + val;
        lazy[v].second = mode;
        return;
    }
    Down(v);
    int tm = ((tl + tr) >> 1);
    UpdateSt(v*2, tl, tm, l, min(r, tm), mode, val);
    UpdateSt(v*2+1, tm+1, tr, max(tm+1, l), r, mode, val);
    st[v] = st[v*2] + st[v*2+1];
}

ll GetSum(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    Down(v);
    int tm = ((tl + tr) >> 1);
    return (GetSum(v*2, tl, tm, l, r) + GetSum(v*2+1, tm+1, tr, l, r));
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
    Solve();
    return 0;
}
