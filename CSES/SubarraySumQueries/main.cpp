#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
struct StNode {
    ll Sum, MaxPref, MaxSuf, Max;
};
int n, m;
ll a[MaxN+1];
StNode st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

StNode Combine(StNode a, StNode b) {
    StNode res;
    res.Sum = a.Sum + b.Sum;
    res.MaxPref = max(a.MaxPref, a.Sum + b.MaxPref);
    res.MaxSuf = max(b.MaxSuf, b.Sum + a.MaxSuf);
    res.Max = max(a.MaxSuf + b.MaxPref, max(a.Max, max(res.Sum, b.Max)));
    return res;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        st[v].Sum = a[tl];
        st[v].MaxPref = max(0LL , a[tl]);
        st[v].MaxSuf = max(0LL, a[tl]);
        st[v].Max = max(0LL, a[tl]);
    }
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr) {
        st[v].Sum = val;
        st[v].MaxPref = max(0LL , val);
        st[v].MaxSuf = max(0LL, val);
        st[v].Max = max(0LL, val);
    }
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void Solve() {
    for (int i=1; i<=m; i++) {
        int k;
        ll x;
        cin >> k >> x;
        UpdateSt(1, 1, n, k, x);
        cout << st[1].Max << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    BuildSt(1, 1, n);
    Solve();
    return 0;
}
