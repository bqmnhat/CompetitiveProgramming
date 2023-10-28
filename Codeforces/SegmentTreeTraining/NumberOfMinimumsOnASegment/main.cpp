#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n, m;
ll a[MaxN+1];
pll st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

pll Combine(pll a, pll b) {
    if (a.first < b.first)
        return a;
    if (b.first < a.first)
        return b;
    return (pll(a.first, a.second + b.second));
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        st[v].first = a[tl];
        st[v].second = 1;
    }
    else {
        int tm =  (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void UpdateById(int v, int tl, int tr, int id, ll NewVal) {
    if (tl == tr) {
        st[v].first = NewVal;
        st[v].second = 1;
    }
    else  {
        int tm = (tl + tr)/2;
        if  (id <= tm)
            UpdateById(v*2, tl, tm, id, NewVal);
        else
            UpdateById(v*2+1, tm+1, tr, id, NewVal);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

pll RMQ(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return pll(1e18, 0);
    if ((l == tl) && (r == tr))
        return st[v];
    int tm = (tl + tr)/2;
    return Combine(RMQ(v*2, tl, tm, l, min(r, tm)), RMQ(v*2+1, tm+1, tr, max(tm+1, l), r));
}

void Solve() {
    int cmd;
    ReadData();
    BuildSt(1, 1, n);
    for (int i=1; i<=m; i++) {
        cin >> cmd;
        if (cmd == 1) {
            int id;
            ll v;
            cin >> id >> v;
            id++;
            UpdateById(1, 1, n, id, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            l++;
            pll ans = RMQ(1, 1, n, l, r);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
