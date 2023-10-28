#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, q;
ll a[MaxN+1], st[4*MaxN+1], stSum[4*MaxN+1], lazy[4*MaxN+1], pref[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakePref() {
    for (int i=1; i<=n; i++)
        pref[i] = pref[i-1] + a[i];
}

//st Sum

void BuildStSum(int v, int tl, int tr) {
    if (tl == tr)
        stSum[v] = a[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildStSum(v*2, tl, tm);
        BuildStSum(v*2+1, tm+1, tr);
        stSum[v] = stSum[v*2] + stSum[v*2+1];
    }
}

void UpdateStSum(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        stSum[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateStSum(v*2, tl, tm, id, val);
        else
            UpdateStSum(v*2+1, tm+1, tr, id, val);
        stSum[v] = stSum[v*2] + stSum[v*2+1];
    }
}

ll SumQueryStSum(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return stSum[v];
    int tm = ((tl + tr) >> 1);
    return (SumQueryStSum(v*2, tl, tm, l, r) + SumQueryStSum(v*2+1, tm+1, tr, l, r));
}

// st max
void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = pref[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

void Down(int v) {
    lazy[v*2] += lazy[v];
    st[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];
    st[v*2+1] += lazy[v];
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
    Down(v);
    int tm = ((tl + tr) >> 1);
    UpdateSt(v*2, tl, tm, l, min(tm, r), val);
    UpdateSt(v*2+1, tm+1, tr, max(tm+1, l), r, val);
    st[v] = max(st[v*2], st[v*2+1]);
}

ll MaxQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return -1e18;
    if ((l <= tl) && (tr <= r))
        return st[v];
    Down(v);
    int tm = ((tl + tr) >> 1);
    return max(MaxQuery(v*2, tl, tm, l, r), MaxQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    for (int i=1; i<=q; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int k;
            ll u;
            cin >> k >> u;
            ll dif = u - a[k];
            a[k] = u;
            UpdateStSum(1, 1, n, k, u);
            UpdateSt(1, 1, n, k, n, dif);
        }
        else {
            int a, b;
            cin >> a >> b;
            ll tmp = MaxQuery(1, 1, n, a, b);
            if (a > 1)
                tmp = tmp - SumQueryStSum(1, 1, n, 1, a-1);
            cout << max(0LL, tmp) << '\n';
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
    MakePref();
    BuildSt(1, 1, n);
    BuildStSum(1, 1, n);
    Solve();
    return 0;
}
