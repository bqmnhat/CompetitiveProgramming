#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxCnt 10
using namespace std;
struct StNode {
    int a[MaxCnt];
    StNode() {
        memset(a, 0, sizeof(a));
    }
} st[4*MaxN+1];
int a[MaxN+1], q, n;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

StNode Combine(StNode Left, StNode Right) {
    StNode res;
    for (int i=0; i<MaxCnt; i++)
        res.a[i] = Left.a[i] + Right.a[i];
    return res;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v].a[a[tl]%10] = 1;
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

StNode GetQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l)) {
        StNode tmp;
        return tmp;
    }
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return Combine(GetQuery(v*2, tl, tm, l, r), GetQuery(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, n);
    for (int i=1; i<=q; i++) {
        int l, r;
        cin >> l >> r;
        StNode tmp = GetQuery(1, 1, n, l, r);
        for (int i = 0; i<MaxCnt; i++)
            cout << tmp.a[i] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CHIANHOM.INP", "r", stdin);
    freopen("CHIANHOM.OUT", "w", stdout);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
