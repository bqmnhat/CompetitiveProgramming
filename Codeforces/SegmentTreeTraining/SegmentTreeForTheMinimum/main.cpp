#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, m;
ll st[4*MaxN+1], a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = a[tl];
    else {
        int tm =  (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

void UpdateById(int v, int tl, int tr, int id, ll NewVal) {
    if (tl == tr)
        st[v] = NewVal;
    else  {
        int tm = (tl + tr)/2;
        if  (id <= tm)
            UpdateById(v*2, tl, tm, id, NewVal);
        else
            UpdateById(v*2+1, tm+1, tr, id, NewVal);
        st[v] = min(st[v*2], st[v*2+1]);
    }
}

ll RMQ(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1e18;
    if ((l == tl) && (r == tr))
        return st[v];
    int tm = (tl + tr)/2;
    return min(RMQ(v*2, tl, tm, l, min(r, tm)), RMQ(v*2+1, tm+1, tr, max(tm+1, l), r));
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
            cout << RMQ(1, 1, n, l, r) << '\n';
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
