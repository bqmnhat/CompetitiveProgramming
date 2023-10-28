#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, m, a[MaxN+1], b[20][MaxN+1];
ll st[20][4*MaxN+1], lazy[20][4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeB() {
    for (int bit=0;  bit<=19; bit++)
        for (int i=1; i<=n; i++)
            b[bit][i] = ((a[i] >> bit)&1);
}

void down(int v, int BitPos, int l, int r) {
    if (lazy[BitPos][v] % 2)
        st[BitPos][v] = (r - l + 1) - st[BitPos][v];
    if (l != r) {
        lazy[BitPos][v*2] += lazy[BitPos][v];
        lazy[BitPos][v*2+1] += lazy[BitPos][v];
    }
    lazy[BitPos][v] = 0;
}

void BuildSt(int v, int tl, int tr, int BitPos) {
    if (tl == tr) {
        st[BitPos][v] = b[BitPos][tl];
    }
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm, BitPos);
        BuildSt(v*2+1, tm+1, tr, BitPos);
        st[BitPos][v] = st[BitPos][v*2] + st[BitPos][v*2+1];
    }
}

void UpdateSt(int v, int tl, int tr, int l, int r, int BitPos) {
    if (lazy[BitPos][v] != 0)
        down(v, BitPos, tl, tr);
    if ((tl > r) || (tr < l))
        return;
    if ((l <= tl) && (tr <= r)) {
        st[BitPos][v] = (tr - tl + 1) - st[BitPos][v];
        if (tl != tr) {
            lazy[BitPos][v*2]++;
            lazy[BitPos][v*2+1]++;
        }
        return;
    }
    int tm = (tl + tr)/2;
    UpdateSt(v*2, tl, tm, l, r, BitPos);
    UpdateSt(v*2+1, tm+1, tr, l, r, BitPos);
    st[BitPos][v] = st[BitPos][v*2] + st[BitPos][v*2+1];
}

ll Query(int v, int tl, int tr, int l, int r, int BitPos) {
    if (lazy[BitPos][v] != 0)
        down(v, BitPos, tl, tr);
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[BitPos][v];
    int tm = (tl + tr)/2;
    return (Query(v*2, tl, tm, l, r, BitPos) + Query(v*2+1, tm+1, tr, l, r, BitPos));
}


void BuildAllSt() {
    for (int i=0; i<=19; i++)
        BuildSt(1, 1, n, i);
}

void QueryType2(int l, int r, int x) {
    for (int i=0; i<=19; i++) {
        int tmp = ((x>>i)&1);
        if (tmp == 1)
            UpdateSt(1, 1, n, l, r, i);
    }
}

ll QueryType1(int l, int r) {
    ll ans = 0;
    for (int i=0; i<=19; i++) {
        ll tmp = Query(1, 1, n, l, r, i);
        ans += (tmp * (1LL << i));
    }
    return ans;
}

void Solve() {
    MakeB();
    BuildAllSt();
    for (int i=1; i<=m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int l, r;
            cin >> l >> r;
            cout << QueryType1(l, r) << '\n';
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            QueryType2(l, r, x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cin >> m;
    Solve();
    return 0;
}
