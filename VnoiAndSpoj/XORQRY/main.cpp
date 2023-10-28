#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
int n, q;
ll a[MaxN+5], st[4*MaxN+5], ans[MaxN+5];
unordered_map<ll, int> LastPos;
struct Query {
    int l, r, id;
} qu[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++) {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
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
        st[v] = st[v*2]^st[v*2+1];
    }
}

ll GetSumXor(int v, int tl, int tr, int l, int r) {
    if ((tr < l) || (tl > r))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (GetSumXor(v*2, tl, tm, l, r) ^ GetSumXor(v*2+1, tm+1, tr, l, r));
}

bool CmpQuery(Query a, Query b) {
    return (a.r < b.r);
}

void Solve() {
    sort(qu+1, qu+1+q, CmpQuery);
    int i = 1, j = 1;
    UpdateSt(1, 1, n, 1, a[1]);
    LastPos[a[1]] = 1;
    while ((i <= n) && (j <= q)) {
        while ((j <= q) && (qu[j].r == i)) {
            ans[qu[j].id] = GetSumXor(1, 1, n, qu[j].l, qu[j].r);
            j++;
        }
        i++;
        if ((i <= n) && (LastPos.find(a[i]) != LastPos.end()))
            UpdateSt(1, 1, n, LastPos[a[i]], 0);
        UpdateSt(1, 1, n, i, a[i]);
        LastPos[a[i]] = i;
    }
    for (int i=1; i<=q; i++)
        cout << ans[i] << ' ';
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
