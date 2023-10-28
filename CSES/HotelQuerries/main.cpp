#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
ll h[MaxN+1], r[MaxN+1], st[4*MaxN+1];
int n, m;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
    for (int i=1; i<=m; i++)
        cin >> r[i];
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
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

int BinSearch(int v, int tl, int tr, ll val) {
    if (st[v] < val)
        return 0;
    while (tl < tr) {
        int tm = ((tl + tr) >> 1);
        if (st[v*2] >= val) {
            tr = tm;
            v = v*2;
        }
        else {
            tl = tm+1;
            v = v*2 + 1;
        }
    }
    return tl;
}

void Solve() {
    for (int i=1; i<=n; i++)
        UpdateSt(1, 1, n, i, h[i]);
    for (int i=1; i<=m; i++) {
        int tmp = BinSearch(1, 1, n, r[i]);
        cout << tmp << ' ';
        if (tmp == 0)
            continue;
        h[tmp] -= r[i];
        UpdateSt(1, 1, n, tmp, h[tmp]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
