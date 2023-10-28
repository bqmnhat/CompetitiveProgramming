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
        st[v] = (a[tl] == 1);
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateById(int v, int tl, int tr, int id) {
    if (tl == tr)
        st[v] = 1 - st[v];
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateById(v*2, tl, tm, id);
        else
            UpdateById(v*2+1, tm+1, tr, id);
        st[v] = st[v*2] + st[v*2+1];
    }
}

int FindKth(int v, int tl, int tr, int k) {
    if (k > st[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr)/2;
    if (k <= st[v*2])
        return FindKth(v*2, tl, tm, k);
    else
        return FindKth(v*2+1, tm+1, tr, k - st[v*2]);
}

void Solve() {
    ReadData();
    BuildSt(1, 1, n);
    int cmd;
    for (int i=1; i<=m; i++) {
        cin >> cmd;
        if (cmd == 1) {
            int id;
            cin >> id;
            id++;
            UpdateById(1, 1, n, id);
        }
        else {
            int k;
            cin >> k;
            k++;
            int ans = FindKth(1, 1, n, k) - 1;
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
