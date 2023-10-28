#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, q;
ll a[MaxN+1], st[4*MaxN+1];
pii lazy[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void down(int v, ll tl, ll tr) {
    ll tm = ((tl + tr) >> 1LL);
    ll AddIn =  ((tm - tl + 1LL)*tl + (((tm - tl + 1LL)*(tm - tl + 2))/2))*lazy[v].second - lazy[v].first*(tm - tl + 1LL);
    lazy[v*2].first += lazy[v].first;
    lazy[v*2].second += lazy[v].second;
    st[v*2] += AddIn;
    AddIn =  ((tr - tm)*(tm+1LL) + (((tr - tm)*(tr - tm + 1LL))/2))*lazy[v].second - lazy[v].first*(tr - tm);
    lazy[v*2+1].first += lazy[v].first;
    lazy[v*2+1].second += lazy[v].second;
    st[v*2+1] += AddIn;
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

void UpdateSt(int v, ll tl, ll tr, ll l, ll r, ll OriginL, ll OriginR) {
    if (l > r)
        return;
    if ((l == tl) && (tr == r)) {
        ll AddIn =  ((r - l + 1LL)*l + (((r - l + 1LL)*(r - l + 2))/2)) - OriginL*(r - l + 1LL);
        lazy[v].first += OriginL;
        lazy[v].second++;
        st[v] += AddIn;
        return;
    }
    down(v, tl, tr);
    ll tm = ((tl + tr) >> 1LL);
    UpdateSt(v*2, tl, tm, l, min(tm, r), OriginL, OriginR);
    UpdateSt(v*2+1, tm+1, tr, max(tm+1LL, l), r, OriginL, OriginR);
    st[v] = st[v*2] + st[v*2+1];
}

ll SumQuerry(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    down(v, tl, tr);
    int tm = ((tl + tr) >> 1);
    return (SumQuerry(v*2, tl, tm, l, r) + SumQuerry(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, n);
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int a, b;
            cin >> a >> b;
            UpdateSt(1, 1, n, a, b, a, b);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << SumQuerry(1, 1, n, a, b) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("POL.INP", "r", stdin);
    //freopen("POL.OUT", "w", stdout);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
