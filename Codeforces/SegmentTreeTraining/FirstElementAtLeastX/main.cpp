#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, m, a[MaxN+1], st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = a[tl];
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

void UpdateById(int v, int tl, int tr, int id, int NewVal) {
    if (tl == tr)
        st[v] = NewVal;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateById(v*2, tl, tm, id, NewVal);
        else
            UpdateById(v*2+1, tm+1, tr, id, NewVal);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

int Binsearch(int x) {
    if (st[1] < x)
        return -1;
    int tl = 1, tr = n, tm, v = 1;
    while (tl != tr) {
        tm = (tl + tr)/2;
        if (st[v*2] >= x) {
            tr = tm;
            v = v*2;
        }
        else {
            tl = tm+1;
            v = v*2+1;
        }
    }
    return tl;
}

void Solve() {
    ReadData();
    BuildSt(1, 1, n);
    int cmd;
    for (int i=1; i<=m; i++) {
        cin >> cmd;
        if (cmd == 1) {
            int id, v;
            cin >> id >> v;
            id++;
            UpdateById(1,1,n,id,v);
        }
        else {
            int x;
            cin >> x;
            int ans = Binsearch(x);
            if (ans != -1)
                ans--;
            cout << ans << '\n';
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
